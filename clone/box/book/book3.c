// blade-book.c

inherit ITEM;
inherit F_UNIQUE;
void create()
{
	set_name( "佻������ܼ�",({ "wlbook3","wlbook3"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long","����һ��ʧ�����������ܼ���\n");
		set("value", 0);
                set("treasure",1);
		set("no_put", 1);
		set("material", "paper");
		set("skill", ([
                        "name":         "huanhua-jian",      //name of the skill
                        "exp_required": 100000 ,        //minimum combat experience required
			"jing_cost":    20+random(100),// jing cost every time study this
			"difficulty":	30,           // the base int to learn this skill
			"min_skill":	0,           // the minimum level you can learn
			"max_skill":	300            // the maximum level you can learn
		]) );
	}
}
