#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("飞狐全集"NOR, ({ "book" }) );
            set("no_put", 1);
            set("value", 0);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	        
            set("unit", "本");
            set("material", "paper");
            set("long", "一本由神书合并成的卷册，你可以用(chayue)来查阅它。\n");
          }

    setup();
}
void init()
{
   add_action("do_cha","chayue");
}
int do_cha()
{
	object me,corpse;
	int exp,pot,score;
	me =this_player();
	exp = 5900+random(2900);
	             pot = exp*2/3;
             score = random(120)+20;
             me->add("combat_exp",exp);
             me->add("potential",pot);
             me->add("score",score);
     	      message_vision("$N仔细地查阅了一遍"+this_object()->query("name")+"。\n", me);
tell_object(me,"你被奖励了：\n" +
             chinese_number(exp) + "点实战经验\n"+
             chinese_number(pot) + "点潜能\n" +
            chinese_number(score)+"点江湖阅历\n");
if (random(4)==0)
{
        corpse=new("/clone/gem/gem");
if (corpse->query("level") >4
&& random(2)>0)
{
        corpse=new("/clone/gem/gem");
}


message("channel:chat", HIM"【江湖谣言】听说"+me->name() + "通过神书任务找到了一颗"+corpse->query("name")+HIM"!"NOR"。\n", users());
             corpse->move(me);
}

	destruct(this_object());
return 1;
}
