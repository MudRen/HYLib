inherit ITEM;
inherit F_UNIQUE;
 
void create()
{
        set_name("������Ҫ", ({ "blade book","book", }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
             set("long",
        "����һ���ñ���д�ɵ��顣���飺��������Ҫ����\n"
        "��Ƥ���ƣ������Ѿ�����ܾ��ˡ�\n",

        );
                set("value", 5000);
                set("material", "silk");
                set("skill", ([
                        "name":       "blade",
                        "exp_required": 100000,
                        "jing_cost":  40,
                        "difficulty": 30,
                        "max_skill":  199,
                        "min_skill":  0
                ]) );
        }
}
