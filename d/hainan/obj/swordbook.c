// literate.c

inherit ITEM;

void create()
{
        set_name("��άĦ������", ({"jing", "book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	set("long", "һ����Щ���Ƶ���.\n");
        set("material", "paper");
        set("skill", ([
                        "name": "buddhism",
                        "exp_required": 600,
                        "jing_cost": 25,
                        "difficulty": 25,
                        "max_skill": 60,
]) );
        }
}

