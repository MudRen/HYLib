// literate.c

inherit ITEM;

void create()
{
        set_name("�������նɾ���", ({"jing", "book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	set("long", "һ���ܾɵ��顣\n");
        set("material", "paper");
        set("skill", ([
                        "name": "dodge",
                        "exp_required": 500,
                        "jing_cost": 20,
                        "difficulty": 20,
                        "max_skill": 140,
]) );
        }
}

