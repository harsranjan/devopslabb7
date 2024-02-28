import React from 'react';
import ReactDOM from 'react-dom/client';

function App() {
  const [todos, setTodos] = useState(() => {
    const savedTodos = localStorage.getItem('todos');
    return savedTodos ? JSON.parse(savedTodos) : [];
  });

  const addTodo = (text) => {
    setTodos([...todos, { text, completed: false }]);
  };

  const toggleTodo = (id) => {
    setTodos(
      todos.map((todo, index) => (index === id ? { ...todo, completed: !todo.completed } : todo))
    );
  };

  const removeTodo = (id) => {
    setTodos(todos.filter((todo, index) => index !== id));
  };

  useEffect(() => {
    localStorage.setItem('todos', JSON.stringify(todos));
  }, [todos]);

  return (
    <div className="App">
      <h1>My Todo App</h1>
      <TodoForm onSubmit={addTodo} />
      <TodoList todos={todos} onToggle={toggleTodo} onRemove={removeTodo} />
    </div>
  );
}

function TodoForm({ onSubmit }) {
  const [text, setText] = useState('');

  const handleSubmit = (e) => {
    e.preventDefault();
    onSubmit(text);
    setText('');
  };

  return (
    <form onSubmit={handleSubmit}>
      <input type="text" value={text} onChange={(e) => setText(e.target.value)} placeholder="Add a new todo..." />
      <button type="submit">Add Item</button>
    </form>
  );
}

function TodoList({ todos, onToggle, onRemove }) {
  return (
    <ul>
      {todos.map((todo, index) => (
        <li key={index} className={todo.completed ? 'completed' : ''}>
          <input type="checkbox" checked={todo.completed} onChange={() => onToggle(index)} />
          <span>{todo.text}</span>
          <button onClick={() => onRemove(index)}>Remove</button>
        </li>
      ))}
    </ul>
  );
}

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <React.StrictMode>
    <App />
  </React.StrictMode>
);
