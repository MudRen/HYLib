// xiang.c
#include <ansi.h>
inherit ITEM;


void create()
{
	set_name("�ص���", ({ "guandi xiang", "xiang" }) );
	set("gender", "����" );
	set("unit", "��");
	set("value", 1);
	set("kar", random(21));
	set("no_get", 1);
	set("no_put", 1);
	set("no_get_from", 1);
        set("long", 	
"����һ��������ǰ����"HIG"����"HIR"����"NOR"���������ף�������ִ�������
�ص�ҹ�������񡣺����ߣ�����һλ"HIW"���װ���"NOR"���������죬���ǹ�ƽ��
����һ����"BLK"��������"NOR"������"HIC"�������µ�"NOR"�ģ������ܲ��ˡ�\n");
}

