inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("���", ({ "hong cha","cha" }));
        set_weight(1000);
        if( clonep() )
            set_default_object(__FILE__);
        else {
        set("long",
"����һ����ɫ���졢��ζŨ�����ϵȺò衣�ǻ����������д������õġ�!\n");
                set("unit", "��");
                set("value", 20);
                set("max_liquid", 10);
        }
        set("liquid", ([
            "name" : "���",
            "remaining" : 8,
        	"type" : "water"
        ]) );
        set("liquid_type", "water");
        setup();
}
