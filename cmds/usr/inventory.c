// inventory.c
// by Find.

#include <ansi.h>

inherit F_CLEAN_UP;

string inventory_desc(object ob,object me);

int main(object me, string arg)
{
	object *inv, ob,*muti;
	int n;
	string output;
	mixed groups;

	if( wizardp(me) && arg ) {
		ob = find_player(arg);
		if( !ob ) ob = find_living(arg);
		if( !ob ) ob = present(arg, environment(me));
	}

	if( !ob ) ob = me;

	inv = all_inventory(ob);
	if( !sizeof(inv) ) {
		write((ob==me)? "Ŀǰ������û���κζ�����\n"
			: ob->name() + "����û��Я���κζ�����\n");
		return 1;
	}

	output = sprintf("%s���ϴ���������Щ����(���� %d%%)��\n",
		(ob==me)? "��": ob->name(),
		(int)ob->query_encumbrance() * 100 / (int)ob->query_max_encumbrance());

	muti = filter_array(inv,(: !$1->is_character()&&!$1->query("equipped")&&!$1->query_amount() :));
	if(sizeof(muti))
	{
		inv -= muti;
		groups = unique_array(muti,(: sprintf("%s%s",base_name($1),$1->name()) :));
	}

	n = sizeof(inv);
	for(int i=0;i<n;i++)
	{
		if(inv[i]->is_character())
			output += sprintf("  %s\n",inv[i]->short());
		else if(inv[i]->query("equipped") || inv[i]->query_amount())
			output += inventory_desc(inv[i],ob);
	}

	if(sizeof(groups))
	{
		foreach(object *group in groups)
		{
			if( (n=sizeof(group)) == 1)
				output += sprintf("  %s\n",group[0]->short());
			else
				output += sprintf("  %s%s%s\n",chinese_number(n),
					group[0]->query("unit"),
					group[0]->query("base_cname")?
					sprintf("%s(%s)",group[0]->query("base_cname"),
					capitalize(group[0]->query("id"))):
					group[0]->short());
		}
	}

	write(output);
	return 1;
}

string inventory_desc(object ob,object me)
{
	return sprintf("%s%s\n",
		ob->query("equipped")?
			((ob == me->query_temp("secondary_weapon"))?
			HIC "��" NOR:
			HIC "��" NOR):
			"  ",
		ob->short()
	);
}

int help (object me)
{
        write(@HELP
ָ���ʽ: inventory
 
���г���Ŀǰ������Я����������Ʒ��

"��" ���˵������ƷΪ���Ѿ�װ��
     �ı��������Ѵ����Ļ��ס�
"��" ���˵���˱���װ����������֡�

ע : ��ָ����� " i " ���档
 
HELP
);
        return 1;
}
