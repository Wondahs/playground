import { Link } from "react-router-dom";

const NotFound = () => {

  return ( 
    <div className="not-found">
      <h1>Not Found</h1>
      <p>The page you seek does not yet exist</p>
      <Link to='/'>Go Back Home</Link>
    </div>
   );
}

export default NotFound;