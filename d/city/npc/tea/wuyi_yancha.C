//Cracked by Roath
// xQin 6/00

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("�����Ҳ�", ({ "wuyi yancha","cha" }));
        set_weight(1000);
        if( clonep() )
            set_default_object(__FILE__);
        else {
        set("long",
"����һ�������Ҳ裬�������е����顣��������Ȼ�ɫ���峺������Ҷ��������ҶԵ��죬\n");
                set("unit", "��");
                set("value", 30);
                set("max_liquid", 10);
        }
        set("liquid", ([
            "name" : "�����Ҳ�",
            "remaining" : 8,
                "type" : "water"
        ]) );
        set("liquid_type", "water");
        setup();
}

