
 
inherit ITEM;
inherit F_FOOD;

int do_eat(string arg);

void create()
{
   set_name("������", ({"cha"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "���ǾŽ�����¥�������衣\n");
                set("unit", "��");
                set("value",300);
                set("no_decay",1);
                set("food_remaining",80);
                set("food_supply",80);
        }
}

void init()
{
  add_action("do_eat","eat");
}

int do_eat(string arg)
{
   object ob;
   ob=this_player();
   if(!arg||arg!="cha")
   return notify_fail("��Ҫ��ʲô��\n");
   if(environment(this_object())!=ob)
   return notify_fail("������û�����������\n");
   ob->add("food",80);
   ob->add("water",80);
   message_vision("$N����һ��"+query("name")+"������������ˡ�\n",ob);
   destruct(this_object());
   return 1;
}