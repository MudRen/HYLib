#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string str)
{
	int i = 0;
int size,size2;
string wiz_status;
    object obj,riding;
	object ob, *inv;

    if( !str || str == "")
        obj = me;
    else if ( !obj = present(str,environment(me)))
        return notify_fail("�������: �Ҳ���"+str+"\n");
    
        size=sizeof(filter_array(all_inventory(me), (: ! $1->query("equipped") :)));
        size2=sizeof(filter_array(all_inventory(me), (: ! $1->query("equipped") :)));
//         printf(" ���� %d �� ���ߡ�\n", size);
//         printf(" ���� %d �� ���ߡ�\n", size2);

	inv = all_inventory(obj);
	while( i < sizeof(inv) && i >= 0 )
	{
		if( inv[i]->query_temp("is_rided_by") == obj->query("id") )
		{
			ob = inv[i];
			i = -10;
		}
		i++;
	}

        if (ob)
        {
                message_vision("$Nһͷ��$n��������������\n",
                              obj, ob);
                obj->delete_temp("is_riding");
                ob->delete_temp("is_rided_by");
                ob->move(environment(me));
        }

wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" 
	&& userp(me) && wizardp(me) && obj!=me)
message("channel:chat", HIC"����Ҽල��"+me->name() + "��ȫ�ָ���" + 
                  obj->query("name")+HIC"����������!"NOR"��\n", users());

    tell_object(obj,HIR + this_player()->query("name") + "(" + this_player()->query("id")+ ")Ϊ�������ָ��������״̬��\n"NOR);
    obj->set("eff_qi",obj->query("max_qi"));
    obj->set("qi",obj->query("max_qi"));
    obj->set("eff_jing",obj->query("max_jing"));
    obj->set("jing",obj->query("max_jing"));
    obj->set("jingli",obj->query("max_jingli"));
    obj->set("neili",obj->query("max_neili")*2);
    obj->set("food",obj->max_food_capacity()*2);
    obj->set("water",obj->max_water_capacity()*2);
if (!obj->query_condition("killer"))
    obj->clear_condition();
    write(HIR"�ָ��ɹ���!!!\n"NOR);
    return 1;
}

int help(object obj)
{
  write(@HELP
ָ���ʽ : xfull <����>

���ô�ָ�����ȫ�ָ������״̬��
HELP
    );
    return 1;
}

