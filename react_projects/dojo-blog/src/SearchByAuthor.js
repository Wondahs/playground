import useFetch from "./useFetch";

const SearchByAuthor = () => {

  const { data: blog, isPending, error } = useFetch('http://localhost:8000/blogs');

  return ( 
    
   );
}

export default SearchByAuthor;