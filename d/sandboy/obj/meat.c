inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("����", ({ "meat" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��Ѫ���ܵ�����,��Ѫһ�εεص�����.\n");
		set("unit", "��");
		set("value", 10);
                set("eat_msg","$N������˺��һ��Ѫ���ܵ�$n,���̻��ʳ�������.\n");
		set("food_remaining",8);
		set("food_supply", 60);
	}
}
