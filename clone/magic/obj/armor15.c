// majia.c
// by steel
#include "armor.h"
#include "ansi.h"

inherit ARMOR;

void create()
{
	set_name(HIY "�漣֮��" NOR, ({ "light fu","lightfu"}) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIY"\n����һ���漣֮��,�������侫�¡������й���������!\n"NOR);
		set("unit", "��");
                set("value", 50000);
                set("treasure",1);       
                set("wield_neili", 2000);
                set("no_give",1);
                set("no_get",1);
                set("no_put",1);

                set("armor_prop/dexterity",10);
                set("armor_prop/constitution",10);
                set("wield_maxneili", 3000);
                set("wield_str", 30);        
                set("wear_msg",HIY"һ��ҫ�۵Ĺ�â���� ��$N�����ϴ������漣֮����\n"NOR);
                set("unequip_msg",HIY"$N���漣֮�����¡�ҫ�۵Ĺ�âҲ������ʧ�ˡ�\n"NOR);
		set("armor_prop/armor", 600);
	}
	setup();
}

int ob_hit(object ob, object me, int damage)
{
   int neili,a;
if (random(5)==0)
{
message_vision(HIC"$N�����ϣ�������ʥ֮�¹⣬���ϵ������˲���!\n"NOR, me,ob);
if((int)me->query("qi") < ((int)me->query("max_qi")-600))
        {
        me->add("qi",500);
        me->add("eff_qi",500);
if (me->query("qi") > me->query("max_qi"))
me->set("qi",me->query("max_qi"));
if (me->query("eff_qi") > me->query("max_qi"))
me->set("eff_qi",me->query("max_qi"));
        }
message_vision(HIC"$n���еĹ���ȫ��ʥ֮�¹⵵ס��\n"NOR, me,ob);
return 0;
}	
else   return damage;
}