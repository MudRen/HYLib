// �˳������xkx�ϰ汾makelove.c ������ȫ�޸ĳ�¹���ǰ汾���Ǻ�
// makelove.c Modify By linux 1999-2000
// makelove.c add baby By ����Щ��(linux) 2000

#include <ansi.h>
void over(object,object);
void over1(object,object);
void over2(object,object);
void over3(object,object);
void over4(object,object);

int main(object me, string arg)
{
        object obj;
        object *ob;

        int i;

        if(!arg || !objectp(obj = present(arg, environment(me))))
                return notify_fail("�����˭������\n");

        if( !obj->is_character()||me->query("gender")==obj->query("gender") )
                return notify_fail("����...�������²��аɣ�\n");

        if(!living(obj))
                return notify_fail("�˼Ҷ������ˣ��㻹...\n");

	if( me->is_busy() )
	return notify_fail("( ����һ��������û����ɡ�)\n");
	if( me->is_busy() )
	return notify_fail("( ����һ��������û����ɡ�)\n");

        if( me->query("gender") =="����" )
                return notify_fail("��һ��̫�࣬Ҳ������°������ǲ��Ǹ�Ц��\n");

        if( obj->query_condition("huaiyun") > 0)
                return notify_fail("��Ц�����и�Ҫע�ⱦ����ȫ����ô����������һ������\n");

        if( me->query_condition("huaiyun") > 0)
                return notify_fail("��Ц�����и�Ҫע�ⱦ����ȫ����ô����������һ������\n");

        if( !environment(me)->query("sleep_room")||
                environment(me)->query("no_sleep_room"))
                return notify_fail("�ܵ��Ҹ���ܰ����ĵط��ɡ�\n");

	if( me->is_busy() )
	return notify_fail("( ����һ��������û����ɡ�)\n");
	if( me->is_busy() )
	return notify_fail("( ����һ��������û����ɡ�)\n");
	if( me->is_busy() )
	return notify_fail("( ����һ��������û����ɡ�)\n");
	if( me->is_busy() )
	return notify_fail("( ����һ��������û����ɡ�)\n");

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++)
                if( ob[i]->is_character()&&ob[i]!=me
                        &&ob[i]!=obj&&!wizardp(ob[i]) )
                        return notify_fail("������б����أ��಻����˼ѽ��\n");
        if(!me->query_temp("makelove/quest")) {
                if((me->query("gender")=="����")) {
                        message_vision(YEL "$N�����ע����$n��˫��§��$n��С������\n���������$n��С����....\n"NOR,me,obj);
                        tell_object(obj, HIR "������������㹲��������\n�����Ը�⣬����Ҳ��" + me->name() + "("+(string)me->query("id")+")"+ "��һ�� makelove ָ�\n" NOR);
                }
                else {
                        message_vision(YEL "$N��С���������˵ģ���������ס$n�Ĳ��ӣ���ǰ����������$n��\n���ţ�С���ཱུĴ��������������$n���촽....\n"NOR,me,obj);
                        tell_object(obj, HIR "ɵ��Ҳ�ܿ�����������㹲��������\n�����Ը�⣬����Ҳ��" + me->name() + "("+(string)me->query("id")+")"+ "��һ�� makelove ָ�\n" NOR);
                }
                obj->set_temp("makelove/quest",1);

        }
        else {
                if((me->query("gender")=="����")) {
                        message_vision(YEL "$N���˺ð��죬ʵ���ܲ���$n������\nͻȻһ�ѽ�$n������סѹ�ڴ���....\n"NOR,me,obj);
                        call_out("over", 1, me,obj);
                }
                else {
                        message_vision(YEL "$N������������$n���ȵ���������ͷС¹ײ����ͣ��\n����̱����$n�Ļ����$nһ�Ѻᱧ������������ķ��ڴ���....\n"NOR,me,obj);
                        call_out("over", 3, obj,me);
                }
                me->delete_temp("makelove/quest");
        }


        return 1;
}


void over(object me,object obj)
{
        message_vision(HIB"...�����"+HIR"����"+HIB"��������...\n"NOR,me);
        if(me->query("qi")<30||me->query("jing")<30||obj->query("qi")<30||obj->query("jing")<30)
        {
                if(me->query("qi")<30||me->query("jing")<30) {
                        message_vision(HIR "$NͻȻ������Ѫ���ε��ڵء����������������ˡ�\n"NOR,me);
                        me->unconcious();
                          me->add("makeloved",1);
                          obj->add("makeloved",1);
                }
                else {
                        message_vision(HIR "$NͻȻ������Ѫ���ε��ڵء����������������ˡ�\n"NOR,obj);
                        obj->unconcious();
                          obj->add("makeloved",1);
                          me->add("makeloved",1);
                }
        }
        else
        switch(random(10)) {
                case 0:
                        message_vision(HIR "$NͻȻ���һ������Ȼ�Ǽ����˷ܣ������ž�������ȥ��\n"NOR,me);
                        me->unconcious();
                        obj->add("qi",obj->query_str()-55+random(10));
                        obj->add("jing",obj->query_con()-55+random(10));
                          obj->add("makeloved",1);
                          me->add("makeloved",1);
                        break;
                case 1:
                        message_vision(HIR "$NͻȻ���һ������Ȼ�Ǽ����˷ܣ������ž�������ȥ��\n"NOR,obj);
                        obj->unconcious();
                        me->add("qi",obj->query_str()-55+random(10));
                        me->add("jing",obj->query_con()-55+random(10));
                          obj->add("makeloved",1);
                          me->add("makeloved",1);
                        break;
                default:
                        if(random(10) > 7) {
                                message_vision(YEL "$N����һ����ͷ�������һ������΢΢������$n��\n��˵����Ҫ��Ȼ...��������һ��...\n"NOR,me,obj);
                          obj->add("makeloved",1);
                          me->add("makeloved",1);
                        }
                        else {
                                message_vision(HIM "$n�����۾����������ڴ��ϣ��е��Լ����ϵ��·�\nһ��һ���ı��ѵ���ͻȻ$n�е�$N���̵�����ѹ�����Լ�...\n"NOR,me,obj);
                                call_out("over1", 3, me,obj);
                        }
                obj->add("qi",obj->query_str()-55+random(10));
                obj->add("jing",obj->query_con()-55+random(10));
                obj->add("makeloved",1);
                me->add("qi",obj->query_str()-55+random(10));
                me->add("jing",obj->query_con()-55+random(10));
                me->add("makeloved",1);                
        }
}
void over1(object me,object obj)
{
                message_vision(HIR "$N���������$n�Ĵ������ƿ�ʼ�����ֵĸ���$n��\n������Ӱ�ļ�����$n����������˫�������ı�ס$N...\n"NOR,me,obj);
                call_out("over2", 3, me,obj);
}

void over2(object me,object obj)
{
                message_vision(WHT "$NҲԽ��Խ�˷ܣ����ں�$n��Ϊһ�壬ֻ��$n\n�����Ӱ�ġ�����������һ��������ʹ�࣬�������...\n"NOR,me,obj);
                call_out("over3", 3, me,obj);
}

void over3(object me,object obj)
{
                message_vision(HIW "$N�Ķ���Խ��Խ�죬Խ��Խ�ͣ�$n�������$N�Ľ���\n�ͷų���$N�İ�����������,�������ڣ���������...\n"NOR,me,obj);
                call_out("over4", 3, me,obj);
}

void over4(object me,object obj)
{
                message_vision(HIM "��ӿ���ȵĸ߳�����$n��˳������$N�Ļ������\n$N����������$N����ĸ�Ū��$n�⻬��Ƥ������������...\n"NOR,me,obj);
                obj->add("qi",obj->query_str()-55+random(10));
                obj->add("jing",obj->query_con()-55+random(10));
                obj->add("makeloved",1);
                me->add("qi",obj->query_str()-55+random(10));
                me->add("jing",obj->query_con()-55+random(10));
                me->add("makeloved",1);
if(obj->query("gender")=="Ů��")
{
        if ((random(obj->query("makeloved")) > 30) && (random(me->query("makeloved")) > 30) && (!(obj->query_condition("huaiyun"))) 
         && random(2)==1)
        {
                obj->set("fuqi/father",me->query("id"));
        message("shout", HIR "������ϲ�¡���"HIM"��ϲ "HIY""+ me->query("name") +"(" + me->query("id") +")"HIM"��"HIY""+ obj->query("name") +"(" + obj->query("id") +")"HIM"����׼��ĸ��\n" NOR,users());
                message_vision(HIY "\n$NͻȻ����һ����Ż�������ߺ�������ҧҧ���������Ǹ������ġ�\n"NOR, obj);
                message_vision(HIM "\n$N�����ˡ��Ͽ�֪ͨ���ӵİְ�"+ obj->query("fuqi/father") +"����������\n"NOR, obj);
                obj->apply_condition("huaiyun",1200);           
                obj->set("long", HIY "\n"+ obj->query("name") +""NOR"ͦ�Ÿ�����ӣ�һ����֪���ǻ����ˣ�����ɢ����һ�ɴ����ĸ����\n"NOR);
                me->set("makeloved",1);
                obj->set("makeloved",1);

        }
}
}

int help(object me)
{
        write(@HELP
ָ���ʽ : makelove <����>
������
���֪ʶ�ο����С������������α�

HELP);
        return 1;
}



