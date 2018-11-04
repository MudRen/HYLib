// box.c ������

#include <ansi.h>

inherit ITEM;

void create()
{
	object money;
	set_name("��Ե��", ({ "shanyuan xiang", "xiang"}));
	set_weight(3000);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ�����ﳣ���Ĺ����䣬ר����������������Ů�ǵľ�\n");
		set("material", "wood");
		set("no_get",1);
		set("no_drop",1);
	}
	setup();
	money=new("/clone/money/gold.c");
	money->set_amount(random(3));
	money->move(this_object());
}

int is_container() { return 1; }

void init()
{
	add_action("do_put","put");
}

int do_put(string arg)
{
	object me, obj;
	string item, target; 
	int amount;

	me = this_player();

	if(!arg) return notify_fail("��Ҫ��ʲô�����Ž����\n");

	if( sscanf(arg, "%s in %s", item, target)!=2) return 0;
	if( target!="xiang"&&target!="gongde xiang") return 0;
	if (sscanf(item,"%d %s",amount,item)!=2)	{
		if(!objectp(obj=present(item,me)))	return 0;
		if(!obj->query("money_id"))	{
			tell_object(me,"���²�����Щ������\n");
			return 1;
		}
		else	{
			tell_object(me,"������Ҫ����ٰ���\n");
			return 1;
			}
	}
	if (!objectp(obj = present(item, me)) ) return 0;

	if(!obj->query("money_id"))	{
		tell_object(me,"���²������ֶ�����\n");
		return 1;
	}
	if(amount>obj->query_amount())	return 0;
	if(amount*obj->query("base_value")>=1000)
	{
		me->set_temp("oldsix_flag/money",1);
			return 0;
		}
	if(amount*obj->query("base_value")<1000)
	{
		tell_object(me,"���ĳ��ⲻ����\n");
		message_vision(HIY"$N����Ե�����Ļ��˹�ȥ��\n"NOR,me);
		return 1;
	}
	return 1;
}
