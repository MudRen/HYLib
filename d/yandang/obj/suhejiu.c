inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("�պ����", ({ "xiangjiu","jiu" }) );
        set("long", "һ�������ҩ��,����������Ƴ�.\n");
        set("unit", "ƿ");
        set("weight", 700);
        set("value", 10000);
	  set("max_liquid", 15);

}

void init()
{
        add_action("do_drink", "drink");
}

int do_drink(string arg)
{
        object ob;
	if( !living(this_player()))	return 0;
        if( !id(arg) ) return notify_fail("��Ҫ��ʲ�᣿\n");
if( living(this_player()) ==0 ) return 0;
        ob=this_player();
        ob->set("jing",(int)ob->query("eff_jing"));
        ob->set("eff_jing",(int)ob->query("eff_jing"));
        write("����˼����պ����.\n");
	set("liquid", ([
		"type": "alcohol",
		"name": "�պ����",
		"remaining": 15,
		"drunk_apply": 4,
	]));

        return 1;
}
