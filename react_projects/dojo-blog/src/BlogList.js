import { useState } from "react";
import { Link } from "react-router-dom";

const BlogList = ({ blogs, title, setData }) => {

    const [author, setAuthor] = useState('');

    const handleSearch = (e) => {
        e.preventDefault();
        const filtered = blogs.filter((blog) => blog.author === author);
        setData(filtered);
    }

    return (
        <div className="blog-list">
            <form onSubmit={handleSearch}>
                <label>Search By Author</label>
                <input
                    type="text"
                    name="author"
                    value={author}
                    onChange={(e) => setAuthor(e.target.value)}
                    placeholder="Enter author name"
                />
                <button>Search</button>
            </form>
            <h1>{blogs.length > 0 ? title : ""}</h1>
            {blogs.map((blog) => (
                <div className="blog-preview" key={blog.id}>
                    <Link to={`/blogs/${blog.id}`}>
                        <h2>{blog.title}</h2>
                        <p>Written by {blog.author}</p>
                    </Link>
                </div>
            ))}
        </div>
    );
}

export default BlogList;
