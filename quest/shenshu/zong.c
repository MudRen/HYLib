#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("����ˮ����"NOR, ({ "book" }) );
            set("no_put", 1);
            set("value", 0);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	        
            set("unit", "��");
            set("material", "paper");
            set("long", "һ��������ϲ��ɵľ�ᣬ�������(chayue)����������\n");
          }

    setup();
}
void init()
{
   add_action("do_cha","chayue");
}
int do_cha()
{
	object me,ob,corpse;
	int exp,pot,score,i;
	me =this_player();
	exp = 6500+random(3500);
	             pot = exp*2/3;
             score = random(300)+100;
             me->add("combat_exp",exp);
             me->add("potential",pot);
             me->add("score",score);
		i=random(6);
	     message_vision("$N��ϸ�ز�����һ��"+this_object()->query("name")+"��\n"NOR, me);
tell_object(me,HIW"�㱻�����ˣ�\n" +
             chinese_number(exp) + "��ʵս����\n"+
             chinese_number(pot) + "��Ǳ��\n" +
            chinese_number(score)+"�㽭������\n"NOR);
if (random(3)==0)
{
        corpse=new("/clone/gem/gem");
if (corpse->query("level") >4
&& random(3)>0)
{
        corpse=new("/clone/gem/gem");
}

message("channel:chat", HIM"������ҥ�ԡ���˵"+me->name() + "ͨ�����������ҵ���һ��"+corpse->query("name")+HIM"!"NOR"��\n", users());
             corpse->move(me);
}

	if (i>4) {
        if ( me->query("per")< 26)
        {
	me->add("per",1);tell_object(me,HIM"�Լ�һ����ò��\n"NOR);
        }
	}
	else if (i>3) {
        if ( me->query("dex")< 26)
        {
	me->add("dex",1);tell_object(me,HIM"�Լ�һ������\n"NOR);
	}
	}
	else if(i>2)	{
        if ( me->query("str")< 26)
	{
	me->add("str",1);tell_object(me,HIC"�Լ�һ�������\n"NOR);
	}
	}
	else if(i>1)	{
        if ( me->query("int")< 26)
	{
	me->add("int",1);tell_object(me,HIR"�Լ�һ�����ԡ�\n"NOR);
	}
	}
	else if(i>0)	{
        if ( me->query("con")< 26)
	{
	me->add("con",1);tell_object(me,HIM"�Լ�һ����ǡ�\n"NOR);
	}
	}
	else {
        if ( me->query("kar")< 26)
	{
	me->add("kar",1);tell_object(me,HIM"�Լ�һ�㸣Ե��\n"NOR);
	}
	}
        ob=new("/clone/box/book/book"+(random(12)+1));
        ob->move(me);
message("channel:chat", HIC"���������š�"GRN + me->query("name")+"�õ�"+HIR"ʧ��������ܼ�:" + ob->query("name")+HIG"����\n"NOR,users() );

if (random(3)==1)
{
        ob=new(__DIR__"sdan");
        ob->move(me);
        ob=new(__DIR__"sdan");
        ob->move(me);
        ob=new(__DIR__"sdan");
        ob->move(me);
message("channel:chat", HIC"���������š�"GRN + me->query("name")+"�õ�����"+HIY":" + ob->query("name")+HIG"����\n"NOR,users() );
}
	destruct(this_object());
return 1;
}
