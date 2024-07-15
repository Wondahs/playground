/* eslint-disable no-unused-vars */
import { useState, useEffect } from 'react';
import BlogList from './BlogList';
import useFetch from './useFetch';

const Home = () => {
    const {data: blogs, setData, isPending, error} = useFetch('http://localhost:8000/blogs');
    const [author, setAuthor] = useState('');

    const handleSearch = () => {
        const filtered = blogs.filter((blog) => blog.author === author);
        setData(filtered);
    }

    return (
        <div className="home">
            {error && <div>{error}</div>}
            {isPending && <div>Loading...</div>}
            <form>
                <label>Search By Author</label>
                <input
                    type="text"
                    name="author"
                    value={author}
                    onChange={(e) => setAuthor(e.target.value)}
                    placeholder="Enter author name"
                />
                <button onClick={handleSearch}>Search</button>
            </form>
            {blogs && <BlogList blogs={blogs} title="All Blog Posts" />}
        </div>
    );
}

export default Home;
