// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIW"���콣"NOR,({ "yitian jian","jian"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long",        HIW"����һ��ͨ�������Ľ����������أ������Ͽ��š�����һ����˭�����桱��\n"NOR);
		set("value",1000000);
		set("material", "steel");
		set("oldsix/qjdy",1);
		set("zhengzhao",1);
	}
	init_sword(25);

// These properties are optional, if you don't set them, it will use the
// default values.

        set("wield_msg", HIW"ֻ�������һ����һ��ҫ�۵�����������$N�����ж��˰����콣��\n"NOR);
        set("unwield_msg", HIW"����զ��,$N���е����콣�Ѿ���������Ľ����ڡ�\n"NOR);

// The setup() is required.

	setup();
}

mixed weapon_action(object me,object victim)
{
	object ob,target_weapon;
	string msg;
	target_weapon=victim->query_temp("weapon");
	if(! target_weapon)	return 0;
	if( target_weapon->query("oldsix/qjdy"))	{
		msg=HIW"��������һ����"+this_object()->query("name")+HIW"��"+
		target_weapon->query("name")+HIW"�ཻ��ð�������ǣ�\n"NOR;
		return msg;
	}
	msg=HIW"ֻ���׹�һ����"+victim->query("name")+HIW"���е�"+target_weapon->query("name")+HIW"��"+this_object()->query("name")+HIW"��Ϊ���Σ�\n"NOR;
			ob=target_weapon;
			ob->unequip();
                        ob->move(environment(victim));
                        ob->set("name", "�ϵ���" + ob->query("name"));
			ob->set("value",0);
                        ob->set("weapon_prop", 0);
                        victim->reset_action();
			return msg;

}
int move(mixed dest)
{
        if(! userp(dest))       return ::move(dest);
        if( ::move(dest)==0)    return 0;
	message("channel:rumor",YEL"��ҥ�ԡ�"+ "ĳ�ˣ����콣��"+
        dest->query("name")+"�������ˣ�\n"NOR,users());
        return 1;
}
