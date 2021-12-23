import Burger from './burger';
import { Nav, Logo, Image } from './styles';
import logoName from '../../assets/navbar/logo.png';
import { Link } from 'react-router-dom';

export default function Navbar({ open, setOpen }) {
  return (
    <Nav>
      <Logo>
        <Link to={"/"}>
            <Image src={logoName} alt="Logo"/>
        </Link>
      </Logo>
      <Burger open={open} setOpen={setOpen} />
    </Nav>
  );
}
