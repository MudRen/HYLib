inherit ITEM;
void create()
{
  set_name("���㵰", ({"egg", "danyan egg"}));
  set_weight(60);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "һö���㵰,˵�����ܷ����������ء�\n");
    set("unit", "ö");
    set("value", 50);
  }
}


