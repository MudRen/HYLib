// literate.c

inherit ITEM;

void create()
{
        set_name("�����������", ({"jing", "book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	set("long", "һ���¾ɵ���װ�顣\n");
        set("material", "paper");
        set("skill", ([
                        "name": "force",
                        "exp_required": 10,
                        "jing_cost": 10,
                        "difficulty": 10,
                        "max_skill": 120,
]) );
        }
}

