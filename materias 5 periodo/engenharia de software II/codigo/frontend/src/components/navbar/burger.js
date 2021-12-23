import RightNav from './rightNav';
import { StyledBurger } from './styles';

export default function Burger({ open, setOpen }) {
  return (
    <>
      <StyledBurger open={open} onClick={() => setOpen(!open)}>
        <div />
        <div />
        <div />
      </StyledBurger>
      <RightNav open={open} setOpen={setOpen} />
    </>
  );
}
