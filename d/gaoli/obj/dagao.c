
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("���", ({"da gao","gao"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�������Ĵ�⣬�������ܺóԡ�\n");
                set("no_decay",1);
                set("unit", "��");
                set("value", 100);
                set("food_remaining", 30);
                set("food_supply", 50);
        }
}
/*
int is_get_of(object pal,object ob)
{
  if(pal->query("family/family_name")!="�Ľ���")
  return notify_fail("ֻ���Ľ��ɵ��ӿ��Լ�����Ķ�������\n");
  return 1;
*/
