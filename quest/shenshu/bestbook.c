#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIR"��������"NOR, ({ "shenshu king" }) );
            set("no_put", 1);
            set("shenshu", 1);
            set("value", 0);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	        
            set("unit", "��");
            set("material", "paper");
            set("long", "�����е����飬�������(chayue)����������\n");
          }

    setup();
}
void init()
{
   add_action("do_cha","chayue");
}
int do_cha(string arg)
{
	object me,ob;
	int exp,pot,score,i;
	me =this_player();
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

        ob=new(__DIR__"sdan");
        ob->move(me);
        ob=new(__DIR__"sdan");
        ob->move(me);
        ob=new(__DIR__"sdan");
        ob->move(me);
        ob=new(__DIR__"sdan");
        ob->move(me);
        ob=new(__DIR__"sdan");
        ob->move(me);
        ob=new(__DIR__"sdan");
        ob->move(me);
        ob=new(__DIR__"sdan");
        ob->move(me);
        ob=new(__DIR__"sdan");
        ob->move(me);
        ob=new(__DIR__"sdan");
        ob->move(me);
        ob=new(__DIR__"sdan");
        ob->move(me);
        ob=new(__DIR__"sdan");
        ob->move(me);
        ob=new(__DIR__"sdan");
        ob->move(me);
        ob=new(__DIR__"sdan");
        ob->move(me);
        ob=new(__DIR__"sdan");
        ob->move(me);
        ob=new(__DIR__"sdan");
        ob->move(me);
        ob=new(__DIR__"sdan");
        ob->move(me);
i=random(6);
message("channel:chat", HIC"���������š�"GRN + me->query("name")+"����˾������񣬵�ʮ����"+HIY":" + ob->query("name")+HIG"����\n"NOR,users() );
	if (i>4) {
        if ( me->query("per")< 41)
        {
	me->add("per",1);tell_object(me,HIM"�Լ�һ����ò��\n"NOR);
        }
	}
	else if (i>3) {
        if ( me->query("dex")< 31)
        {
	me->add("dex",1);tell_object(me,HIM"�Լ�һ������\n"NOR);
	}
	}
	else if(i>2)	{
        if ( me->query("str")< 31)
	{
	me->add("str",1);tell_object(me,HIC"�Լ�һ�������\n"NOR);
	}
	}
	else if(i>1)	{
        if ( me->query("int")< 31)
	{
	me->add("int",1);tell_object(me,HIR"�Լ�һ�����ԡ�\n"NOR);
	}
	}
	else if(i>0)	{
        if ( me->query("con")< 31)
	{
	me->add("con",1);tell_object(me,HIM"�Լ�һ����ǡ�\n"NOR);
	}
	}
	else {
        if ( me->query("kar")< 41)
	{
	me->add("kar",1);tell_object(me,HIM"�Լ�һ�㸣Ե��\n"NOR);
	}
	}
        ob=new("/clone/box/book/book"+(random(12)+1));
        ob->move(me);
message("channel:chat", HIC"���������š�"GRN + me->query("name")+"�õ�"+HIR"ʧ��������ܼ�:" + ob->query("name")+HIG"����\n"NOR,users() );
	destruct(this_object());
return 1;
}
