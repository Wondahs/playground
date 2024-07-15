import { useNavigate, useParams } from "react-router-dom";
import useFetch from "./useFetch";

const BlogDetails = () => {
  const { id } = useParams();
  const { data: blog, isPending, error } = useFetch('http://localhost:8000/blogs/' + id);

  const navigate = useNavigate();

  const handleClick = () => {
    fetch('http://localhost:8000/blogs/' + id, {
      method: 'DELETE'
    }).then(() => {
      console.log('Blog Deleted');
      navigate('/');
    });
  }
  return (
    <div className="blogdetails">
      {isPending && <div className="ispending">Loading...</div>}
      {error && <div>{error.message}</div>}
      {blog && (
        <article>
          <h1>{blog.title}</h1>
          <p className="author" >Written By {blog.author}</p>
          <p>{blog.content}</p>
          <button onClick={handleClick}>Delete Blog</button>
        </article>
      )}
    </div>
  );
}

export default BlogDetails;
