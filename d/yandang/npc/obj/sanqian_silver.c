// silver.c

inherit MONEY;

void create()
{
	set_name("��Ǯɢ������", ({"sanqian_silver", "ingot", "silver_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "silver");
		set("long", "�׻��������ӣ��˼��˰������ӡ�\n");
		set("unit", "��");
		set("base_value", 30);
		set("base_unit", "��");
		set("base_weight", 10);
	}
	set_amount(1);
}

