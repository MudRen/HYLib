// kill.c
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
    int my_idle,your_idle;
    object obj,ob;
    string callname,msg;;
    if (!me)    return 0;
        if (userp(me) && !query_heart_beat(me))
        {
         "/cmds/usr/quithy"->main(me);
return notify_fail("������û�������������µ�½!!\n");
        }

//    if (me->is_fighting()) 
//        return notify_fail("���������������!\n");

    if( !arg )
        return notify_fail("����ɱ˭��\n");

    if(!objectp(obj = present(arg, environment(me))) || !me->visible(obj))
        return notify_fail("����û������ˡ�\n");

    if( environment(me)->query("no_fight") && !obj->query_condition("killer"))
        return notify_fail("���ﲻ׼ս����\n");

     if( obj->query("env/no_fight") )
        return notify_fail("���ܴ򣬴򲻵ð���\n");
     if( obj->query_temp("no_kill") )
        return notify_fail("���ܴ򣬴򲻵ð���\n");

    if( !obj->is_character() || obj->is_corpse() )
        return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
    if(obj==me)
        return notify_fail("�� suicide ָ���ȽϿ�:P��\n");
    if(me->is_busy())
        return notify_fail("��������æ��û��ɱ�ˡ�\n");
if( !living(obj) && userp(obj) && obj->query("combat_exp")/2 > me->query("combat_exp") )
	return notify_fail("����Ҫɱ���ˣ���������ǿ̫�࣬�㲻�Ҷ��֡�\n");

//pk
    if( userp(obj) && me->query_condition("killer"))
        return notify_fail("���Ѿ���ͨ���ˣ���Ҫ����ɱ����ˣ�\n");
    if( userp(obj) && obj->query("combat_exp") < me->query("combat_exp") && me->query_condition("killer"))
        return notify_fail("���Ѿ���ͨ���ˣ���Ҫ����ɱ����ˣ�\n");


//��սϵͳ
        if (userp(me) && userp(obj)
         && obj->query_temp("nokill") )
        return notify_fail("������������ս�ƣ�\n");

        if (userp(me) && userp(obj)
         && me->query_temp("nokill") )
        return notify_fail("����������ս�ƣ�\n");

    if( userp(me) && userp(obj) && obj->query_condition("nokill")
    && !obj->query_condition("killer"))
        return notify_fail("�Ǹ��˸ձ�ɱ�����Ź����ɣ�\n");
if( !living(obj) && userp(obj) && obj->query("combat_exp")/2 > me->query("combat_exp") )
	return notify_fail("����Ҫɱ���ˣ���������ǿ̫�࣬�㲻�Ҷ��֡�\n");
	
	

        if (userp(obj) && !query_heart_beat(obj)
        && !obj->query_condition("killer"))
        {
         write("������ʲô��\n");
        return notify_fail("������������\n");
//         write("���˲���beg��\n");
        }
    if(userp(me) && userp(obj) && me->is_fighting() && obj->is_fighting()) 
    {
        return notify_fail("���Ѿ��ڴ��ˣ���ɱ�����ҿ����ǲ��еģ�\n");
    }

    if (userp(me)){
    your_idle = obj->query_skill("fadai-qigong",1);
    my_idle = me->query_skill("fadai-qigong",1);
    if(userp(obj)&&random(your_idle)>30 && random(your_idle)>random(my_idle)&&!obj->is_fighting()&&!environment(obj)->query("fight_room"))
    {
         write("�����"+obj->query("name")+"��ɱ�֣����ǿ������Ǵ���ľ�������ӣ���ʼ�պݲ���������\n");
         tell_object(obj,"һ�ֲ���ĸо���������ȫ������\n");
         tell_object(obj,me->query("name")+"("+me->query("id")+")"+"������¶��֣����ڿ����У��㻹�ǿ��Ӱɣ�\n");
         me->start_busy(5);
     }
//    if (wizardp(obj))
//        return notify_fail(obj->query("name")+"������һ�ۣ���ͻȻ�ŵ����ȷ�������������������\n");
    if((int)obj->query("age") <= 17 && userp(obj) && !obj->query_condition("killer"))
        return notify_fail("Ϊ����������ã��Ź�С���Ӱ�.\n");
    if( !living(obj) && userp(obj) && obj->query_temp("sleeped")&&me->query("shen")>obj->query("shen"))
        return notify_fail("���˼�˯����ʱ�����֣��ٺ٣���Ҳ̫ȱ���ˣ�\n");
    }
    callname = RANK_D->query_rude(obj);
        if(me->query("race")=="����"){
                if(me->query("mute"))
                        msg = HIR"\n$NͻȻ����$n��˫��ͨ�죬������Ҫ��$p�����أ���\n\n";
                else if(stringp(me->query("env/kill_msg")) && strlen(me->query("env/kill_msg")) < 50 )
                        msg = "\n$N����$n���һ����"+me->query("env/kill_msg")+"��\n\n";
                else if(me->query("combat_exp") > obj->query("combat_exp")*2){
		        if(me->query("shen") < -10000)
                       msg = HIY"\n$N����$n����һ�ڣ���"+callname+"��������������ʱ��"+RANK_D->query_self_rude(me)+"���쿴�㼫��˳�ۣ������ɣ�����\n\n";
                    else msg = HIY"\n$N����$n�������"+callname+"������Ǻ�"+RANK_D->query_self_rude(me)+"�����֣�������˾ȥ����һ״�ɣ�����\n\n";
		        }
	        else if(obj->query("combat_exp") > me->query("combat_exp")*2){
		        if(me->query("shen") < -10000)
                       msg = HIG"\n$N����$nһ����Ц����"+callname+"��������ƽʱҫ������������"+RANK_D->query_self_rude(me)+"��Ҫȡ������������\n\n";
		        else msg = HIG"\n$N�ٺ�һЦ��$n"+callname+"�����似�����㣬���������ƴ����ҲҪ������ʬ��ϣ���\n\n";
		        }
	        else {
		        if(me->query("shen") < -10000)
                     msg = HIW"\n$N����$n�ͺ�һ������"+callname+"��������Ľ��������ļ��գ���"+RANK_D->query_self_rude(me)+"������·�ɣ�����\n\n";
		        else msg = RED"\n$N����$n�ȵ�����" + callname + "�����������ѵ����������"+RANK_D->query_self_rude(me)+"����������ɣ���\n\n";
	                }
	        }
	else msg = "\n$N���һ������Ȼ����$n��������Ҫ��$pɱ������\n\n";
	message_vision(msg, me, obj);
if (environment(me)->query("no_fight") && userp(obj) && obj->query_condition("killer"))
{
COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
me->start_busy(2);
}
    me->kill_ob(obj);
    if(userp(me) && userp(obj))
    {
         me->start_busy(2);
    }

    me->start_busy(1);
    obj->delete_temp("fighting");
    if ( userp(obj)){
 		if ( me->query("age")<18 )
			me->att_kill_ob(obj);
		}
    if( !userp(obj))
        obj->kill_ob(me);
    else {
        obj->fight_ob(me);
        tell_object(obj, HIR "�����Ҫ��" + me->name() 
            + "�����ಫ������Ҳ���������һ�� kill ָ�\n" NOR);
    }
      if (!userp(me)) return 1;
    if (stringp(obj->query("marry"))){
    ob=present(obj->query("marry"),environment(me));
    if (ob && userp(ob) && living(ob) && ob!=me ){
        if (ob->query("gender")=="����")
            message_vision(CYN"\n$Nһ��ŭ��"+me->name()+"���㾹���۸������ţ��Ҹ���ƴ�ˣ�\n\n"NOR, ob);
        else
            message_vision(CYN"\n$N����һ����"+me->name()+"�������㲻���۷򸾷���������У�\n\n"NOR, ob);
        ob->kill_ob(me); me->fight_ob(ob);
    }
    }
    if( !stringp(callname=obj->query("family/family_name")))
        if( !stringp(callname=obj->query("friend")))
        return 1;
    ob=first_inventory(environment(me));
    while(ob){
        if( ob!=obj && ob->is_character() && !ob->is_corpse() && living(ob)){
//ͬ�Ż�������ҿɲ����룩
        if( !ob->query_temp("no_kill") ) 
        {
            if ( (string)ob->query("family/family_name")==callname && !ob->is_killing(me) && !userp(ob) ){
                message_vision(CYN"\n$N��ŭ��"+me->name()+"���㾹��ı���ҵ�ͬ�ţ����У�\n\n"NOR, ob);
                ob->fight_ob(me); me->fight_ob(ob);
            }
        }
//�ݰѵ��ֵܻ���
        if( !ob->query_temp("no_kill") ) 
        {
            if ((string)ob->query("friend")==callname  || (string)ob->query("friend")==obj->query("id") ){
                message_vision(CYN"\n$N����һЦ��"+me->name()+"����Ҫɱ�Ұݰѵ��ֵܣ����������ң�\n\n"NOR, ob);
                ob->kill_ob(me); me->fight_ob(ob);
            }
        }
        }
        ob=next_inventory(ob);
    }
    return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : kill <����>
 
���ָ������������ʼ����һ�����������ͼɱ���Է���kill �� fight ����
��ͬ���˫�������浶ʵǹ�ش򶷣�Ҳ����˵����������ˡ���� kill ֻ�赥��
��һ����Ը�Ϳ��Գ������������κ���ʹ�� kill ָ��Ὺʼս����ͨ�����
�Է��� NPC �Ļ�������Ҳ��ͬ������ʹ�� kill��
�����˶���ʹ�� kill ָ��ʱ����ֺ�ɫ�����������㣬���һ����Ҷ��ԣ����
��û�ж�һ������ʹ�ù� kill ָ��Ͳ��Ὣ�Է���Ĵ��˻�ɱ��( ʹ�÷�����
��)��
�������ָ��: hit, fight
�й� fight �� kill �������뿴 'help combat'.
HELP
    );
    return 1;
}
 
