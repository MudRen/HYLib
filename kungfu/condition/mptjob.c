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
team=me->query_team();
	  for(i=1;i<count;i++)
      { if(team[i]!=0)
	  { if(team[i]->query("combat_exp")<minexp)
	    minexp=team[i]->query("combat_exp");
		if(team[i]->query("combat_exp")>maxexp)
        maxexp=team[i]->query("combat_exp");
	  }
	  }
for(i=100;i*i*i/10<=maxexp;i++);
maxpot=i;

if(environment(me)->query("short")!=me->query_temp("tjob")
&& duration<17)
{
tell_object(me, HIY "\n��ϸ͵͵����˳ǣ�������ʧ�ܣ�\n" NOR); 
me->delete_temp("tjob");
me->apply_condition("mptjob",0);
return 0;	
}
else     if (!duration)
{
message_vision(HIR"\n$N���˵�ͷ��ɱ����!!\n"NOR,me); 
	     obj=new(__DIR__"npc/jianxi"); 
   	     obj->do_copy(me,maxpot);
   	     obj->set("title",HIR"���ɼ�ϸ"NOR);
  	     obj->move(environment(me));
e=(int)me->query_skill("force",1)*4/5;
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
	     obj->kill_ob(me);me->kill(this_object());
  	     me->delete_temp("tjob");
  	     gift=new(__DIR__"npc/mijian");
  	     gift->set_temp("host",me->query("id"));
  	     gift->move(obj);
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
        me->apply_condition("mptjob", duration - 1);
tell_object(me, RED "\n��������������ϸ�£�\n" NOR); 
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
team=me->query_team();
	  for(i=1;i<count;i++)
      { if(team[i]!=0)
	  { if(team[i]->query("combat_exp")<minexp)
	    minexp=team[i]->query("combat_exp");
		if(team[i]->query("combat_exp")>maxexp)
        maxexp=team[i]->query("combat_exp");
	  }
	  }
for(i=100;i*i*i/10<=maxexp;i++);
maxpot=i;
        if (!me) return;
if (!me->query_temp("tjob")) return;
	    if (random(19)== 0)
	    {
	      obj=new("quest/menpai/jobnpc/btshan");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"����ɽ��������"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
              me->kill(this_object());
	     }
	     else 
	    if (random(19)== 2)
	    {
	      obj=new("quest/menpai/jobnpc/tangmen");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"������������"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
              me->kill(this_object());
	     }
	     else 
	    if (random(19)== 3)
	    {
	      obj=new("quest/menpai/jobnpc/feitian");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"��������������"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
              me->kill(this_object());
	     }
	     else 
	    if (random(19)== 4)
	    {
	      obj=new("quest/menpai/jobnpc/wudujiao");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"�嶾����������"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
              me->kill(this_object());
	     }
	     else 
	    if (random(19)== 5)
	    {
	      obj=new("quest/menpai/jobnpc/lingxiao");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"��������������"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
              me->kill(this_object());
	     }
	     else 
	    if (random(19)== 1)
	    {
	      obj=new("quest/menpai/jobnpc/gumu");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"��Ĺ����������"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 2)
	    {
	      obj=new("quest/menpai/jobnpc/gaibang");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"ؤ������������"NOR);     
              obj->move(environment(me));
   e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 3)
	    {
	      obj=new("quest/menpai/jobnpc/emei");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"��������������"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 4)
	    {
	      obj=new("quest/menpai/jobnpc/dali");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"�������������"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 5)
	    {
	      obj=new("quest/menpai/jobnpc/huashan");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"��ɽ����������"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 6)
	    {
	      obj=new("quest/menpai/jobnpc/kunlun");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"��������������"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 7)
	    {
	      obj=new("quest/menpai/jobnpc/shaolin");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"��������������"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 8)
	    {
	      obj=new("quest/menpai/jobnpc/mr");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"Ľ������������"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 9)
	    {
	      obj=new("quest/menpai/jobnpc/mingjiao");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"������������"NOR);     
                 obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 10)
	    {
	      obj=new("quest/menpai/jobnpc/lingjiu");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"���չ���������"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 11)
	    {
	      obj=new("quest/menpai/jobnpc/taohua");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"�һ�����������"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 12)
	    {
	      obj=new("quest/menpai/jobnpc/xueshan1");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"ѩɽ�ɻ��̵���"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 13)
	    {
	      obj=new("quest/menpai/jobnpc/xueshan2");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"ѩɽ�ɻ��̷���"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 14)
	    {
	      obj=new("quest/menpai/jobnpc/xueshan3");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"ѩɽ����������"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 15)
	    {
	      obj=new("quest/menpai/jobnpc/xingxiu");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"��������������"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 16)
	    {
	      obj=new("quest/menpai/jobnpc/wudang");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"�䵱����������"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 17)
	    {
	      obj=new("quest/menpai/jobnpc/tiezhang");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"���ư���������"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	    else 
	    if (random(19)== 18)
	    {
	      obj=new("quest/menpai/jobnpc/yunlong");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"��������������"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	      obj=new(__DIR__"npc/mengbing");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"�ɹ���ʿ"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
                 obj->kill_ob(me);me->kill(this_object());
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);
}

string query_type(object me)
{
	return "job";
}
