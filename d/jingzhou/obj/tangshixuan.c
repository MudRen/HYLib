//tangshixuan.c

inherit ITEM;

void create()
{
        set_name("��ʫѡע", ({ "tangshi xuanzhu", "xuanzhu" }));
        set_weight(600); 
        set("unique", 1); 
	if( clonep() )
		set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ʫѡע������ϸ���˿������������Ÿ������ε�Ь����\n");
                set("value", 500);
                set("material", "paper");
	     }
 
}

