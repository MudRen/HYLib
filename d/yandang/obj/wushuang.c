#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIM"��˫��"NOR, ({ "wushuang_jian","sword"}) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��"+HIM"��˫��"+NOR+",�����ߴ�����֮һ��\n");
		set("value", 1000);
		set("material", "steel");
	}
	init_sword(880);


      set("wield_msg",
"$N�ӽ����аγ�"+HIM+"��˫��.\n"NOR);
	set("unwield_msg","$N��"+HIM+"��˫��"+NOR+"�������佣��.\n");
       setup();
}
