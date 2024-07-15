import { useState } from "react";
import { useNavigate } from "react-router-dom";

const Create = () => {
  const [title, setTitle] = useState('');
  const [content, setContent] = useState('');
  const [author, setAuthor] = useState('');
  const [isPending, setIsPending] = useState(false);

  const navigate = useNavigate();

  const handleSubmit = (e) => {
    e.preventDefault();
    const blog = { title, content, author };

    setIsPending(true);

    fetch('http://localhost:8000/blogs', {
      method: 'POST',
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify(blog)
    })
      .then(() => {
        console.log('New Blog Added');
        setIsPending(false);
        navigate('/');
      });
  }

  return (
    <div className="create">
      <h2>Create a New Blog</h2>
      <form onSubmit={handleSubmit} >
        <label>Blog Title</label>
        <input
          type="text"
          placeholder="Title"
          required
          value={title}
          onChange={(e) => setTitle(e.target.value)}
        />
        <label>Blog Content</label>
        <textarea
          placeholder="Enter Content"
          required
          value={content}
          onChange={(e) => setContent(e.target.value)}
        />
        <label>Blog Author</label>
        <input type="text"
          placeholder="Enter Your Name Here"
          required
          value={author}
          onChange={(e) => setAuthor(e.target.value)}
        />
        <button type="submit">{isPending ? 'Loading...' : 'Submit'}</button>
      </form>
    </div>
  );
}

export default Create;