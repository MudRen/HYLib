#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat","eat");
}

void create()
{
	       set_name("蜈蚣毒囊", ({"wugong dunang" ,"dunang"}));
	
		set("unit", "个");
		set("long", "这是一个蜈蚣的毒囊。\n");
		set("value", 100);
//            set("no_drop", "这样东西不能离开你。\n");
              set_weight(100);

	
	setup();
}

int do_eat(string arg)
{
    object me = this_player();
    if (arg != "wugong dunang"&& arg !="dunang")
    return 0;
    tell_object(me,  "你想死啊，用suicide比较快一点。\n" );
    return 1;
}
