//MUDǿ������1.1��
//���  �Ĵ���ҵ��ѧ  ��Х����(sword)

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object obj, old_target;
	int n;
        if((string)me->query("gender") == "Ů��")
          return notify_fail(RED"���ʲô?����Ů�˰�!\n"NOR);

        if( environment(me)->query("no_fight") )
                return notify_fail(HIW" ���컯��֮����������.\n\n"NOR);

        if( (int)me->query("age") <= 17)
                return notify_fail(HIY" ������û��������\n"NOR);

        if( me->query("combat_exp") <= 500000)
                return notify_fail(HIY" ��ľ�����ô�ͣ����������߰�!\n"NOR);

        if (!me->query("family/family_name"))
                return notify_fail(HIR"���������ɣ����ǽ�������!\n"NOR);

        if (me->is_busy()) 
                return notify_fail(CYN"��������æ���أ�������\n"NOR);

        if ( wizardp(me) )
                return notify_fail("������ʦ�����...�����˰ɣ�\n");

        if(!arg || !objectp(obj = present(arg, environment(me))))
                return notify_fail(CYN" �������˭��\n"NOR);

        if(!obj->is_character() )
                return notify_fail(CYN" �����һ�㣬�ǲ��������\n"NOR);

        if((string)obj->query("race") == "Ұ��")
          return notify_fail(CYN" ��ʲô�����ֲ����ˣ�\n"NOR);

        if(obj==me)     return notify_fail(HIW" ǿ���Լ�? û��˵����\n"NOR);

        if((string)obj->query("gender") == "����")
          return notify_fail(CYN" ��ͬ�����ɲ��У�\n"NOR);


        if((string)obj->query("gender") == "����")
          return notify_fail(CYN" ����������,�Ҹ�ʲô��!\n"NOR);
        if( !living(obj) )
          return notify_fail("  \n");
        if( me->is_fighting() )
                return notify_fail(HIR"\nר�Ĵ�ܰɣ���\n"NOR);

    if( userp(obj) && me->query_condition("killer"))
        return notify_fail("���Ѿ���ͨ���ˣ���Ҫ����ɱ����ˣ�\n");
    if( userp(obj) && obj->query("combat_exp") < me->query("combat_exp") && me->query_condition("killer"))
        return notify_fail("���Ѿ���ͨ���ˣ���Ҫ����ɱ����ˣ�\n");
 
        if (userp(me) && userp(obj)
         && obj->query_temp("nokill") )
        return notify_fail("������������ս�ƣ�\n");

        if (userp(me) && userp(obj)
         && me->query_temp("nokill") )
        return notify_fail("����������ս�ƣ�\n");

    if( userp(me) && userp(obj) && obj->query_condition("nokill")
    && !obj->query_condition("killer"))
        return notify_fail("�Ǹ��˸ձ�ɱ�����Ź����ɣ�\n");

        if((int)obj->query("age") <= 17 && userp(obj))
                return notify_fail(CYN"�����Ǻ��ӣ��Ź����ɣ�\n"NOR); 

        if( obj->query("env/no_fight") )
                return notify_fail(CYN"���˲������´�ָ�\n"NOR); 

        if(obj->query_temp("no_kill"))
                return notify_fail(CYN"���˲������´�ָ�\n"NOR); 


 else {             
                me->start_busy(2);
                obj->start_busy(2);
                message_vision(HIM"\n$N����$n���һ������������������ү�ҽ�����\n˵�ű������ƻ�����$n���˹�ȥ��\n\n"NOR, me, obj);
                message_vision(HIC"$n����$N���һ����"+RANK_D->query_rude(me)+"�����룬���У�\n"NOR, me, obj);
                me->fight_ob(obj);
                obj->fight_ob(me);
                   //�趨����Ϊ�жԹ�ϵ
                obj->remove_all_enemy(); //��ʱֹͣ�����������������
                for(n=0;n<=random(6)+1;n++)
               {
                COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
                }
            if((int)me->query("qi") <= (int)me->query("max_qi")*3/4)
                call_out("do_leave",1,me,obj);
  else{        
                call_out("do_qiangjian", 2, me, obj); 
                call_out("do_look", 6, me, obj);
                call_out("do_look1", 8, me, obj);

       if((int)obj->query("per") > 22){                //���ǵ����죬��������Ҫ��֧
                call_out("do_qiangjian1", 14, me, obj);
                call_out("do_qiangjian2", 18, me, obj);
                call_out("do_qiangjian3", 22, me, obj);
                call_out("do_qiangjian4", 26, me, obj); //�ͷ���������
                call_out("do_qiangjian5", 32, me, obj);
                call_out("do_qiangjian6", 38, me, obj);  //��
                call_out("do_qiangjian7", 49, me, obj);
                call_out("do_qiangjian8", 61, me, obj);
                call_out("do_qiangjian9", 62, me, obj);

                call_out("do_wakeup",70,me,obj);
                call_out("do_kill",71,me,obj);  
  }   else{
        if((int)obj->query("per") > 17){   
                call_out("do_qiangjian2", 14, me, obj);
                call_out("do_qiangjian4", 19, me, obj); 
                call_out("do_qiangjian6", 25, me, obj);                
                call_out("do_qiangjian7", 31, me, obj);
                call_out("do_qiangjian10", 45, me, obj);
                call_out("do_qiangjian9", 47, me, obj);
                call_out("do_wakeup",57,me,obj);
                call_out("do_kill",58,me,obj);
                                
   }else{
                call_out("do_puke",11,me,obj);      
         }   
      }
      }        
      }
        return 1;   
}

void do_leave(object me,object obj)
{
         if (!me)  return notify_fail("���Ѿ������ˣ�\n");
         if (!obj)  return notify_fail("�Ǹ����Ѿ������ˣ�\n");
        if(objectp(present(obj,environment(me)))){
        tell_object(me,HIY"\n����"+(string)obj->query("name")+"�����ǣ���������Ǵ�����ͷ���߿�Ϊ�ã�\n"NOR, me, obj); 
        tell_object(obj,HIY"\n��������书����"+(string)obj->query("name")+"����������.���ߴ���ˣ��ƺ�����!"NOR);
        me->set("wimpy",100);
        me->start_busy(1);
        call_out("do_hit",0,me,obj);
        call_out("do_setwimpy",5,me,obj);
 }    return;
}

void do_hit(object me, object obj)
{
        if(objectp(present(obj,environment(me)))){
      message_vision(HIC"\n$n����$N���һ��:"+RANK_D->query_rude(me)+"������? û�ţ�������"+RANK_D->query_respect(obj)+"������˵��\n"NOR,me, obj);   
                COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
                COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
                me->fight_ob(obj);
                obj->fight_ob(me);
//                me->move(random(sizeof(keys(environment(me)->query("exits")))));
  }
        return;
}
void do_setwimpy(object me,object obj)
{
         if (!me)  return notify_fail("���Ѿ������ˣ�\n");
         if (!obj)  return notify_fail("�Ǹ����Ѿ������ˣ�\n");

                me->set("wimpy",20);
        return;
}
           
void do_qiangjian(object me, object obj)
{
        mapping my_family;
        string my_fam;
        my_family = me->query("family"); 
        my_fam = my_family["family_name"];
        if(objectp(present(obj, environment(me)))) {
                me->start_busy(100);
                obj->start_busy(100);
        if( !living(obj) )
        message_vision(CYN"\n$N���Ż赹�ڵص�$nЦ��:�������ã����˲���˯������!\n$N��������$n��ǰ������$n�����塣\n"NOR, me, obj); 
       else{
        message_vision(HIM"\n$N��ס��$n��ƴ������,����ץס����һ�ѽ�$n������ס.\n\n"NOR, me, obj);
        tell_object(me,HIY"���������������ס��û��������ֻ�������׸��ˣ�\n"NOR);               

        tell_object(obj,HIY"\n�㻹����ƴ��������\n���α��Է�������ס,ֻ����������������ʲôҲ�����ˡ�\n\n"NOR);
               obj->set_temp("block_msg/all", 1);  
               environment(obj)->add_temp("no_fight",1);
               environment(obj)->add_temp("sleeping_person", 1);
               obj->set("hunmi",1);
           }  
	       CHANNEL_D->do_channel(this_object(), "rumor",
	       sprintf("�ҿ���%s��%s���ڸɻ���!!!!!!!", my_fam, me->name(1))); 
                                                  }     //Ϊpksex���·���
           return;
}

void do_look(object me,object obj)
{     
         if (!me)  return notify_fail("���Ѿ������ˣ�\n");
         if (!obj)  return notify_fail("�Ǹ����Ѿ������ˣ�\n");
        if(objectp(present(obj, environment(me)))) {
        message_vision("\n���ڽ�����ߣ�$N���̲�ס��ϸ������$nһ��\n", me, obj);
                                                   }
           return;
}
void do_look1(object me,object obj)
{     
         if (!me)  return notify_fail("���Ѿ������ˣ�\n");
         if (!obj)  return notify_fail("�Ǹ����Ѿ������ˣ�\n");
        if(objectp(present(obj, environment(me)))) {
   tell_object(me,HIM"\n�����������������˿���û��ע���㣬���ɵ�.....\n"NOR);
                                                   }
           return;
}

void do_puke(object me, object obj)
{
     if(objectp(present(obj, environment(me)))) {
        message_vision(CYN"\n$Nϡ������������һ�ء�\n"NOR, me,obj);
        tell_object(me,HIY"�㲻�ɵö��Լ�˵�������������ϻ�����ô���Ů�ˣ��һ���վԶЩ�ã�\n"NOR);    
        message_vision("\n$NԶԶ���ƿ�$n,��Ц��˵��"+RANK_D->query_respect(obj)+"����ˡ����ݡ�������ʵ���޸�����\n�ղ���ͻ���������£�զ�Ǻ�����ڣ�\n",me,obj); 
        message_vision(CYN"\n����$N����һ����¡�\n"NOR,me,obj);
        me->start_busy(1);
        obj->start_busy(1);
}
         return;
}

void do_qiangjian1(object me,object obj)  
{
         if (!me)  return notify_fail("���Ѿ������ˣ�\n");
         if (!obj)  return notify_fail("�Ǹ����Ѿ������ˣ�\n");
        if(objectp(present(obj, environment(me)))) {
        message_vision("���ţ�$N�Ĵ��ֲ���$n��������$n������������������.......\n", me, obj);   

}

        return;
}
void do_qiangjian2(object me,object obj)  
{
         if (!me)  return notify_fail("���Ѿ������ˣ�\n");
         if (!obj)  return notify_fail("�Ǹ����Ѿ������ˣ�\n");
        if(objectp(present(obj, environment(me)))) {
        message_vision("\n��һ���,$N��Ҳ������ס���е����𣬽�$n���ϵ�����һ��һ���س���\n", me, obj);

}

        return;
}
void do_qiangjian3(object me,object obj)  
{
         if (!me)  return notify_fail("���Ѿ������ˣ�\n");
         if (!obj)  return notify_fail("�Ǹ����Ѿ������ˣ�\n");
        if(objectp(present(obj, environment(me)))) {
        message_vision("\n����һ��˺����$n�������Ѿ���������ɢ����ϣ�����ֻʣ\n", me, obj);
        message_vision("���Ƕ����ߣ��⻬���۵ļ米չ����$N����ǰ�����Ƿ羰���ޣ�\n", me, obj);
        if((int)obj->query("per") >= 30){
        message_vision("\nֻ��$n������ѩ�ף���Ө��͸,�������ˡ�\n",me,obj);}
 }
     return;
}

void do_qiangjian4(object me,object obj)       //Ϊ�����������,���������òΪָ��
                                               //�����˺���,���ڱ�����վ�������ⷽ��
                                               //���Դ˺����������ͷ�����ʹ���ߵ�
{      
         if (!me)  return notify_fail("���Ѿ������ˣ�\n");
         if (!obj)  return notify_fail("�Ǹ����Ѿ������ˣ�\n");
         if(objectp(present(obj, environment(me)))) {

         if((int)obj->query("age") <= 18 ) {
        
         message_vision(HIM"\n��ʱ$NƳ����$n�ֱ��ϵ�'�ع�ɰ',ԭ��$n���Ǵ�Ů��!\n"NOR, me, obj);
         if((int)obj->query("per") >= 30 )
         tell_object(me,HIY"\n���¿ɰ����ֻ��ˣ�����߻����µĴ�Ů�������ټ���\n"NOR);
         if((int)obj->query("combat_exp") <= 5000) {
           me->add("combat_exp", -(int)obj->query("combat_exp")/30);        
         }else{
           me->add("combat_exp", -(int)obj->query("combat_exp")/50);
              }
           me->add("shen",-random(1000));   
                                                       
                                          }
                                          
else{
        if((int)obj->query("age") <= 30 ) {

         message_vision(HIM"\n��˵�Ѳ����Ǵ�Ů,����Ϊ�ٸ���$n�Ƿ�������������Ҳ��$N��������!\n"NOR, me, obj);
           me->add("shen",-random(5000));   
         if((int)obj->query("combat_exp") <= 5000) {
           me->add("combat_exp", -(int)obj->query("combat_exp")/30);
//           me->add("potential", -random((int)me->query("potential")/4));       
         }else{
           me->add("combat_exp", -(int)obj->query("combat_exp")/50);
              }

         }else{ 
           if((int)obj->query("age") >= 55 ) {
         message_vision(HIM"\n����$N�Ѿ����ʵ�������ʳ�ĵز���,��$n��������̫̫Ҳ���Ź�!\n"NOR, me, obj);
         message_vision(HIW"\nС������Ǵ!!!\n"NOR, me, obj);
           me->add("shen",-random(5000)-5000);   
         if((int)obj->query("combat_exp") <= 5000) {
           me->set("combat_exp",random((int)me->query("combat_exp")/4));    //�ͷ����ô�������
         }else{
           me->add("combat_exp", -random((int)me->query("combat_exp")/15));
              }
         }else{
         message_vision(HIM"\n$n�������������,���ȴ�֮��������$N��д̼�!\n"NOR, me, obj); 
           me->add("shen",-random(5000));   
         if((int)obj->query("combat_exp") <= 5000) {
           me->add("combat_exp", -random((int)me->query("combat_exp")/10));
         }else{
           me->add("combat_exp", -random((int)me->query("combat_exp")/20));
                                                 
              }
              }
              }
     }
                                                   }
        return;
}
void do_qiangjian5(object me,object obj)  
{
         if (!me)  return notify_fail("���Ѿ������ˣ�\n");
         if (!obj)  return notify_fail("�Ǹ����Ѿ������ˣ�\n");
        if(objectp(present(obj, environment(me)))) {
        message_vision("\n$N����һ�ӣ�$n���Ͻ�ʣ�ĶǶ�Ҳ���µ��ˣ���һ������������\n", me, obj);
        message_vision("�����$Nֻ�뺰�\n", me, obj);
}

        return;
}
void do_qiangjian6(object me,object obj)  
{
         if (!me)  return notify_fail("���Ѿ������ˣ�\n");
         if (!obj)  return notify_fail("�Ǹ����Ѿ������ˣ�\n");

        if(objectp(present(obj, environment(me)))) {
        message_vision(HIM"\n����$Nһ�ѽ�$n�����ڵ��ϡ���������\n"NOR, me, obj);

}

        return;
}
void do_qiangjian7(object me,object obj)  
{
         if (!me)  return notify_fail("���Ѿ������ˣ�\n");
         if (!obj)  return notify_fail("�Ǹ����Ѿ������ˣ�\n");

        if(objectp(present(obj, environment(me)))) {
        message_vision("\n��������������������\n"NOR, me, obj);
        message_vision("���������ܳ����$N��Ұ�ް�ĺ������$n˺���ѷεĿ���������\n", me, obj);
}

        return;
}
void do_qiangjian8(object me,object obj)  
{
         if (!me)  return notify_fail("���Ѿ������ˣ�\n");
         if (!obj)  return notify_fail("�Ǹ����Ѿ������ˣ�\n");

        if(objectp(present(obj, environment(me)))) {
        message_vision(HIM"\n���ã���ͣ��Ъ��������\n"NOR, me, obj);
        message_vision("$N�������������������Ż�˯�ڵص�$n�������Ц��һ�¡�\n", me, obj);

}
        return;
}
void do_qiangjian9(object me,object obj)  
{	
        mapping my_family;
        string my_fam;
         if (!me)  return notify_fail("���Ѿ������ˣ�\n");
         if (!obj)  return notify_fail("�Ǹ����Ѿ������ˣ�\n");
        my_family = me->query("family"); 
        my_fam = my_family["family_name"];	


        if(objectp(present(obj, environment(me)))) {
        message_vision(HIR"\n��ʱֻ��$Nҡҡ�λΣ����㲻�ȡ�\n"NOR, me,obj);
        tell_object(me,HIR"\nԭ���㷢���Լ�ȫ��������������Ĺ����ˣ�\n\n"NOR);
        me->set("qi",(int)obj->query("eff_qi")/2);

					CHANNEL_D->do_channel(this_object(), "rumor",
					sprintf("%s��%s��%sǿ���ˡ�",obj->name(1), my_fam,me->name(1)));
					CHANNEL_D->do_channel(this_object(), "rumor",
					sprintf("%s���ٸ�ͨ���ˡ�", me->name(1)));

        me->start_busy(1);
        me->apply_condition("killer", 180 +
			me->query_condition("killer"));
        me->apply_condition("sexman", 180 +
			me->query_condition("sexman"));
        me->add("PKS", 1);
}
        return;
}

void do_qiangjian10(object me,object obj)  
{
         if (!me)  return notify_fail("���Ѿ������ˣ�\n");
         if (!obj)  return notify_fail("�Ǹ����Ѿ������ˣ�\n");
        if(objectp(present(obj, environment(me)))) {
        message_vision(HIM"\n���ã���ͣ��Ъ��������\n"NOR, me, obj);
        message_vision("$N�������������Ż�˯�ڵص�$nʧ����̾��һ������������ĵ�ù,��������������'ˮ��'��\n", me, obj);
}
        return;
}
void do_wakeup(object me,object obj)
{
         if (!me)  return notify_fail("���Ѿ������ˣ�\n");
         if (!obj)  return notify_fail("�Ǹ����Ѿ������ˣ�\n");

               obj->set("hunmi",0);            
               obj->set_temp("block_msg/all", 0);
	   if (!environment(obj)->query("sleep_room") && !environment(obj)->query("hotel"))
	       environment(obj)->set("no_fight",0);
     	       environment(obj)->add_temp("sleeping_person", -1);
               obj->set("qi",(int)obj->query("max_qi"));
               obj->set("jing",(int)obj->query("max_jing"));
               tell_object(obj,HIC"\n������������ָ��ò���ˣ�\n"NOR);
               message_vision(HIY"\n$N����������������\n"NOR,obj);
               obj->start_busy(1);

        return;
}
void do_kill(object me,object obj)    
{
         if (!me)  return notify_fail("���Ѿ������ˣ�\n");
         if (!obj)  return notify_fail("�Ǹ����Ѿ������ˣ�\n");

                if(objectp(present(obj, environment(me)))) {
         if((int)obj->query("age") <= 18)
     {
      message_vision(HIC"\n$n������۵ض���$N���һ��:"+RANK_D->query_rude(me)+"���ӣ��������٣��Һ���ƴ�ˣ�\n\n"NOR,me, obj);
                me->fight_ob(obj);
                me->start_busy(10);
                obj->fight_ob(me);
if (!userp(obj)) obj->kill_ob(me);
     }else{  
         if((int)obj->query("age") <= 30)
     {
      message_vision(HIC"\n$n������۵ض���$N���һ��:"+RANK_D->query_rude(me)+"���ӣ����������壬������������,\n���Ժ���ƴ�ˣ�\n\n"NOR,me, obj);
                me->fight_ob(obj);
                me->start_busy(10);
                obj->fight_ob(me);
                if (!userp(obj)) obj->kill_ob(me);
     }else{         
         if((int)obj->query("age") <= 55){
           message_vision(HIW"\n$n����$N���һ��:"+RANK_D->query_rude(me)+"���ӣ���������ף��Һ���ƴ�ˣ�\n\n"NOR,me, obj);
                me->fight_ob(obj);
                me->start_busy(10);
                obj->fight_ob(me);
                if (!userp(obj)) obj->kill_ob(me);
     }else{
           message_vision(HIW"\n$n����$N���һ��:"+RANK_D->query_rude(me)+"���ӣ���������ڲ���������������������������\n���Ժ���ƴ��\n\n"NOR,me, obj);
                me->fight_ob(obj);
                me->start_busy(10);
                obj->fight_ob(me);
                if (!userp(obj)) obj->kill_ob(me);
     }
     }
     }
                                                         }
        return;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : qiangjian <����>
   
   �������޷粻����,�����������������ٲ��˲ɻ����ģ�
���ӹ�������µ��ﲮ���,������������������ǵ�.
�����ɻ�����������Ϊ����,���һ�Ҫ������ֵ��ִ�����
û��һ���汾��,���е��ܲ��ˡ�
   �е���'���в�����Ա�'����֮����֮����֮��
��Ȼ���˾���ĪΪ֮��
HELP
    );
    return 1;
}
