#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
object obj,gift;
    object *team;
        int j;
	mapping npc,mp;
	mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;
	string sex;
	object ob, weapon;
	int k,a,b,c,d,e,f,temp;
int maxpot,maxexp,minexp;      
     int i=0,count=0;
maxexp=me->query("combat_exp");
for(i=100;i*i*i/10<=maxexp;i++);
maxpot=i;

if(environment(me)->query("short")!=me->query_temp("mjtjob")
&& duration<17)
{
tell_object(me, HIY "\n�������ɱ�����ˣ�������ʧ�ܣ�\n" NOR); 
me->delete_temp("mjtjob");
me->apply_condition("mjtjob",0);
return 0;	
}
else     if (!duration)
{
message_vision(HIR"\n$N���˵�����ɱ����!!\n"NOR,me); 
				obj=new("/quest/menpaijob/mingjiao/jianxi"); 
				obj->do_copy(me,maxpot);

				obj->set("title",HIG"��������"NOR);
                                obj->set_temp("hostmj",me->query("id"));
				obj->move(environment(me));
e=(int)me->query_skill("force",1)*2/3;
if (!me->query_skill("force")) e=320;
if (e<= 300) e=320;
if (mapp(skill_status = obj->query_skills()))//�ж��Լ��Ƿ��й������н����������ȫ��ɾ��
{
skill_status = obj->query_skills();
sname = keys(skill_status);//���������Լ��Ĺ�������
temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
obj->set_skill(sname[i],e);//ɾ���Լ����й���
}				
				message_vision(HIY"$N��Ц���ѣ���ƾ���Ǽ���Ҳ�뵲ס�ҵ�ȥ·?\n"NOR, obj);
				obj->kill_ob(me);
      return 0;
}
else  	 if( duration%3==0 && duration <17
		 &&!environment(me)->query("no_fight")
		 )
       {  me->start_busy(1);
          call_out("zuji", 0, me);    
     
	 }
if (!environment(me)->query("no_fight"))
{
        me->apply_condition("mjtjob", duration - 1);
tell_object(me, RED "\n�������Ҫɱ���ˣ������Ԯ��\n" NOR); 
}
        return 1;
}


void zuji(object me)
{   
    object *team,obj,gift;
int maxpot,maxexp,minexp;      

        int j;
	mapping npc,mp;
	mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;
	string sex;
	object ob, weapon;
	int k,a,b,c,d,e,f,temp;
 
     int i=0,count=0;
maxexp=me->query("combat_exp");
for(i=100;i*i*i/10<=maxexp;i++);
maxpot=i;
        if (!me) return;
if (!me->query_temp("mjtjob")) return;
if (random(20)>15)
			{ obj=new("/quest/menpaijob/mingjiao/wudang");   
	          obj->do_copy(me,maxpot,3);
	          obj->set("title",HIY"�䵱�ɵ���"NOR);     
              obj->move(environment(me));
              e=(int)me->query_skill("force",1)*2/3;
if (!me->query_skill("force")) e=320;
if (e<= 300) e=320;
if (mapp(skill_status = obj->query_skills()))//�ж��Լ��Ƿ��й������н����������ȫ��ɾ��
{
skill_status = obj->query_skills();
sname = keys(skill_status);//���������Լ��Ĺ�������
temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
obj->set_skill(sname[i],e);//ɾ���Լ����й���
}
              obj->kill_ob(me);
			}
		     else 
			{
	  	      obj=new("/quest/menpaijob/mingjiao/emei"); 
		      obj->do_copy(me,maxpot,1);
	          obj->set("title",HIG"�����ɵ���"NOR);
	          obj->move(environment(me));
e=(int)me->query_skill("force",1)*2/3;
if (!me->query_skill("force")) e=320;
if (e<= 300) e=320;
if (mapp(skill_status = obj->query_skills()))//�ж��Լ��Ƿ��й������н����������ȫ��ɾ��
{
skill_status = obj->query_skills();
sname = keys(skill_status);//���������Լ��Ĺ�������
temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
obj->set_skill(sname[i],e);//ɾ���Լ����й���
}
              obj->kill_ob(me);
	          obj=new("/quest/menpaijob/mingjiao/shaolin");
	           obj->set("title",HIW"�����ɵ���"NOR);
		      if (random(20)>5)
			  {obj->do_copy(me,maxpot,2);
	           obj->set("title",HIW"�����ɵ���"NOR);
			  }
			   else 
               obj->do_copy(me,maxpot,1);
		       obj->move(environment(me));
e=(int)me->query_skill("force",1)*2/3;
if (!me->query_skill("force")) e=320;
if (e<= 300) e=320;
if (mapp(skill_status = obj->query_skills()))//�ж��Լ��Ƿ��й������н����������ȫ��ɾ��
{
skill_status = obj->query_skills();
sname = keys(skill_status);//���������Լ��Ĺ�������
temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
obj->set_skill(sname[i],e);//ɾ���Լ����й���
}
               obj->kill_ob(me);
}
}

string query_type(object me)
{
	return "job";
}
