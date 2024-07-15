import { useEffect, useState } from "react";
import { Link } from "react-router-dom";

const BlogList = ({ blogs, title, setData }) => {

    const [author, setAuthor] = useState('');
    const [displayBlog, setDisplayBlog] = useState(blogs)

    useEffect(() => {
        const filtered = blogs.filter((blog) => blog.author.toLowerCase().includes(author.toLowerCase()));
        setDisplayBlog(filtered);
    }, [author, blogs, setData]);

    const handleSearch = (e) => {
        setAuthor(e.target.value);
    }

    return (
        <div className="blog-list">
            <form onSubmit={e => e.preventDefault()}>
                <input
                    type="text"
                    name="author"
                    value={author}
                    onChange={handleSearch}
                    placeholder="Enter author name"
                />
            </form>
            <h1>{author === '' ? title : `Blogs by ${author}`}</h1>
            {displayBlog.length === 0 ? <p>`No results found for ${author}`</p> :
            displayBlog.map((blog) => (
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
