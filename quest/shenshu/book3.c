#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIY"�������"NOR, ({ "sdxl" }) );
            set("no_put", 1);
            set("value", 0);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	      
            set("unit", "��");
            set("material", "paper");
            set("long", "����֮һ,�������������Ӣ�۴������������Ǿ���(combine)��\n");
          }

    setup();
}
void init()
{
    add_action("do_combine","combine");
}
int do_combine()
{
	object me,newbook,*inv,ob;
	int sizeinv;
	me = this_player();
	newbook =new(__DIR__"3book");
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("���Ȱ����ϵ��˷��°�!!\n");
       		
		}
// if (!present("yttlj", me)||!present("sdyxz",me))
    if (!(ob = present("yttlj", me)) ||
        !(ob = present("sdyxz", me)))	
	tell_object(me,"�����û��.\n");
  else{
        if( ob->query("ownmake"))
	return notify_fail("�������мٻ��ɡ�\n");
        if(userp(ob))
	return notify_fail("�������мٻ��ɡ�\n");
        if( ob->is_character() || ob->is_corpse() )
	return notify_fail("�������мٻ��ɡ�\n");
    if(!ob->query("dynamic_quest"))
	return notify_fail("�������мٻ��ɡ�\n");

       message_vision("$N�Ѵӻ��з��������Ӣ�۴��������������������飬�����е�������ºϲ�����һ����\n", me);
	newbook->move(me);
	destruct(present("yttlj",me));
	destruct(present("sdyxz",me));
	destruct(this_object());}
return 1;
}