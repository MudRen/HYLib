inherit ITEM;
inherit F_UNIQUE;
 
void create()
{
        set_name("�ڹ���Ҫ�²�", ({ "force book2","zhenjing2", }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
             set("long",
        "����һ���ñ���д�ɵ��顣���飺�ڹ���Ҫ(��)����\n"
        "�ʷ��������ף���������Ů���ֱʡ�\n",
        );
                set("value", 1000);
                set("material", "silk");
                set("skill", ([
                        "name":       "force",
                        "exp_required": 10000,
                        "jing_cost":  30,
                        "difficulty": 20,
                        "max_skill":  299,
                        "min_skill":  199
                ]) );
        }
}
