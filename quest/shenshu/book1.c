#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIR"Ц������"NOR, ({ "xajh" }) );
    set_weight(1);
            set("no_put", 1);
            set("value", 0);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	        
            set("unit", "��");
            set("material", "paper");
            set("long", "����֮һ��\n");
          }

    setup();
}

void init()
{
    add_action("do_zhuang","he");
}
int do_zhuang(string arg)
{
	object me,newbook,ob;
	object *inv;
	int sizeinv;

	me = this_player();


 	if (arg!="jinbooka")
	return notify_fail("��Ҫ�ϲ�ʲô��\n");
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("���Ȱ����ϵ��˷��°�!!\n");
       		
		}
	newbook =new(__DIR__"jbook1");

    if (!(ob = present("sjec", me)) ||
        !(ob = present("sdxl", me)) ||
!(ob = present("xkx", me)) ||
!(ob = present("yttlj", me)) ||
!(ob = present("bxsword", me)) ||
!(ob = present("yyblade", me)) 
        )
	tell_object(me,"�����û��.\n");
  else {
        if( ob->query("ownmake"))
	return notify_fail("�������мٻ��ɡ�\n");
        if(userp(ob))
	return notify_fail("�������мٻ��ɡ�\n");
        if( ob->is_character() || ob->is_corpse() )
	return notify_fail("�������мٻ��ɡ�\n");
    if(!ob->query("dynamic_quest"))
	return notify_fail("�������мٻ��ɡ�\n");
        message_vision("$N�Ѵӻ��з�����Ц�������б�ԧ�߱��飬������һ����\n", me);
	newbook->move(me);
	destruct(present("sjec",me));
	destruct(present("sdxl",me));
	destruct(present("xkx",me));
	destruct(present("bxsword",me));
	destruct(present("yttlj",me));
	destruct(present("yyblade",me));

	destruct(this_object());}
return 1;
}
