#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIR"��ӹȫ���ϲ�"NOR, ({ "jin booka" }) );
            set("no_put", 1);
            set("value", 0);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	        
            set("shenshu",1);
            set("unit", "��");
            set("no_put", 1);
            set("material", "paper");
            set("long", "һ��������ϲ��ɵľ�ᣬ�������(chayue)��������������������С������Ļ���������(try)����\n");
          }

    setup();
}
void init()
{
   add_action("do_cha","chayue");
   add_action("do_try","try");
}
int do_cha(string arg)
{
	object me,corpse;
	int exp,pot,score;
	me =this_player();
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	exp = 8800+random(8000);
	             pot = exp*2/3;
             score = random(200)+100;
             me->add("combat_exp",exp);
             me->add("potential",pot);
             me->add("score",score);
     	      message_vision("$N��ϸ�ز�����һ��"+this_object()->query("name")+"��\n", me);
tell_object(me,"�㱻�����ˣ�\n" +
             chinese_number(exp) + "��ʵս����\n"+
             chinese_number(pot) + "��Ǳ��\n" +
            chinese_number(score)+"�㽭������\n");
if (random(2)==0)
{
        corpse=new("/clone/gem/gem");
if (corpse->query("level") >4
&& random(2)>0)
{
        corpse=new("/clone/gem/gem");
}


message("channel:chat", HIM"������ҥ�ԡ���˵"+me->name() + "ͨ�����������ҵ���һ��"+corpse->query("name")+HIM"!"NOR"��\n", users());
             corpse->move(me);
}
	destruct(this_object());


return 1;
}
int do_try(string arg)
{
	object me,newbook,ob;
	me = this_player();
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	newbook =new(__DIR__"jinbook");

    if (!(ob = present("jin bookb", me))
        )
	tell_object(me,"�����û��.\n");
   else{
        if( ob->query("ownmake"))
	return notify_fail("�������мٻ��ɡ�\n");
        if( !ob->query("shenshu"))
	return notify_fail("�������мٻ��ɡ�\n");
        if(userp(ob))
	return notify_fail("�������мٻ��ɡ�\n");
        if( ob->is_character() || ob->is_corpse() )
	return notify_fail("�������мٻ��ɡ�\n");
        message_vision("$N���Ű���������������ϳ�һ�������Ͼ�Ȼ�ɹ��ˡ�\n", me);
	newbook->move(me);
	destruct(present("jin bookb",me));
	destruct(this_object());}return 1;
}
