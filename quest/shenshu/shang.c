#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("����ˮ�����ϲ�"NOR, ({ "shangbook" }) );
            set("no_put", 1);
            set("value", 0);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	        
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
int do_cha()
{
	object me,corpse,ob;
	int exp,pot,score;
	me =this_player();
	exp = 3900+random(2900);
	             pot = exp*2/3;
             score = random(20)+50;
             me->add("combat_exp",exp);
             me->add("potential",pot);
             me->add("score",score);
     	      message_vision("$N��ϸ�ز�����һ��"+this_object()->query("name")+"��\n", me);
tell_object(me,"�㱻�����ˣ�\n" +
             chinese_number(exp) + "��ʵս����\n"+
             chinese_number(pot) + "��Ǳ��\n" +
            chinese_number(score)+"�㽭������\n");
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

if (random(3)==1)
{
        ob=new(__DIR__"sdan");
        ob->move(me);
message("channel:chat", HIC"���������š�"GRN + me->query("name")+"�õ�һ��"+HIY":" + ob->query("name")+HIG"����\n"NOR,users() );
}


	destruct(this_object());
return 1;
}
int do_try()
{
	object me,newbook,ob;
		object *inv;
	int sizeinv;
	me = this_player();
	newbook =new(__DIR__"zong");
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("���Ȱ����ϵ��˷��°�!!\n");
       		
		}
// if (!present("xiabook", me))
    if (!(ob = present("tfyizhan", me)) ||
        !(ob = present("sdmingbu", me)))
    return notify_fail("ȱ���Ĵ��������Ʒ�һս�ϵ�ƴ�鷽��!\n");

    if (!(ob = present("xiabook", me)) ||
        !(ob = present("tfyizhan", me))||
        !(ob = present("sdmingbu", me)))
	tell_object(me,"�����û��.\n");
   else{
        if( ob->query("ownmake"))
	return notify_fail("�������мٻ��ɡ�\n");
        if(userp(ob))
	return notify_fail("�������мٻ��ɡ�\n");
        if( ob->is_character() || ob->is_corpse() )
	return notify_fail("�������мٻ��ɡ�\n");
        message_vision("$N���Ű���������������ϳ�һ�������Ͼ�Ȼ�ɹ��ˡ�\n", me);
	newbook->move(me);
	destruct(present("xiabook",me));
	destruct(present("tfyizhan",me));
	destruct(present("sdmingbu",me));
	destruct(this_object());}return 1;
}
