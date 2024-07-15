import { useEffect, useState } from "react";

const useFetch = (url) => {
  const [data, setData] = useState(null);
  const [isPending, setIsPending] = useState(true);
  const [error, setError] = useState(null);

  useEffect(() => {

    const abortConst = new AbortController();

    fetch(url, { signal: abortConst.signal })
      .then(res => {
        if (!res.ok) throw Error('Could not fetch the resource');
        return res.json()
      })
      .then(data => {
        setData(data);
        setIsPending(false);
        setError(null);
      })
      .catch((err) => {
        err.message && console.log(err.message);
        if (err.name === 'AbortError') {
          console.log('Fetch Aborted');
        } else {
          setIsPending(false);
          setError(err.message);
          setData(null);
        }
      });

    return () => abortConst.abort('Navigated away from page');
  }, [url]);

  return { data, setData, isPending, error }
}

export default useFetch;