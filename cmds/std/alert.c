
int main(object me, string arg)
{
   string HUFA_FILE = "/d/biwu/hufa.c";
   object hufa;
   int i;

object *enemy;
   seteuid(getuid());
        
	if(!present("mostaff",me) && !present("shenstaff",me))
		return notify_fail("ֻ��ͨ�����Ȼ�ħ�Ȳ����ٻ�������\n");
		if( environment(me)->query("no_fight") )
		return notify_fail("����û���˴򶷣�\n");
   //last 0 means do not show position.

   if( (int)me-> query_temp("number") > 1 )
     return notify_fail("��ֻ���ٻ���λ����!\n");
   if (me->query("jing")<100) 
	return notify_fail("�㾫����!!\n");
   if ((int)me->query_condition("zdizi_busy"))  
        return notify_fail("����й�����!!\n");


   me->save();


   message_vision("ֻ��$N���һ�������һ������ڣ�������\n", me);
   hufa = new(HUFA_FILE);
   hufa->move(environment(me));
   	 hufa->set_name(me->query("name")+"���󻤷�",({"dizi"}));
   hufa->set("combat_exp",me->query("combat_exp")/2);
   hufa->set("possessed", me);
   hufa->show(me);

   hufa = new(HUFA_FILE);
   hufa->move(environment(me));
	 hufa->set_name(me->query("name")+"���һ���",({"dizi"}));
   hufa->set("combat_exp",me->query("combat_exp")/2);
   hufa->set("possessed", me);

   hufa->show(me);
    me->add_temp("number", 2);


    me->apply_condition("zdizi_busy",6);
    me->add("jing",-100); 
	   	if(me->is_fighting()) {
  enemy = me->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			hufa->kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(hufa);
			else enemy[i]->kill_ob(hufa);
		}
	}
//me->remove_all_killer();
	}
      return 1;
}
 


int help(object me)
{
    write(@HELP
ָ���ʽ: alert 
 
��Ϊ������а���ɵ��������������ٻ����������������Լ���
����whisper���Լ��Ļ�����������磬�����Ļ�����aaa-zuo����
whisper aaa-zuo kill xiao er����������ɱ��С����

HELP
    );
   return 1;
}
 
