// unix 1998,10
// modified by wind

#include <ansi.h>
#include <ansi.h>
inherit NPC;
//inherit F_CLEAN_UP;
void del_gaoed(object me);

void init()
{
add_action("do_gao","gao");
add_action("xiao_li","dangguan");
}

void create()
{
	set_name("�ղ�����ǡ�", ({"qin chai", "qin"}));
	set("title", HIY"��ʡ��Ѳ��"NOR);
	set("nick_name", "�ղ����");
        set("gender", "����");
        set("age", 54);
        set("long",
                "���Ǿ��ǻ����������ղ�󳼣������ƹ��ű����Ȩ��\n"
			);

        set("attitude", "peaceful");

        set("str", 27);
        set("int", 25);

	set("neili", 24000);
	set("max_neili", 24000);
	set("jiali", 50);
	set("max_jing", 12000);
	set("eff_jing", 12000);
	set("jing", 12000);
	set("max_qi", 15000);
	set("eff_qi", 15000);
       set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 250);

        set("combat_exp", 5800000);

        set_skill("blade", 70);
        set_skill("force", 80);
        set_skill("parry", 50);
        set_skill("dodge", 60);
	set_skill("literate", 100);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("whip", 200);
	set_skill("blade", 200);
	set_skill("sword", 200);
	set_skill("hand", 200);
	set_skill("claw", 200);
	set_skill("houquan", 300);
	set_skill("yunlong-xinfa", 300);
	set_skill("yunlong-shengong", 300);
	set_skill("wuhu-duanmendao", 300);
	set_skill("yunlong-jian", 300);
	set_skill("yunlong-shenfa", 300);
	set_skill("yunlong-bian", 300);
	set_skill("yunlong-shou", 300);
	set_skill("yunlong-zhua", 300);

	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("unarmed", "houquan");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "yunlong-shou");
	map_skill("claw", "yunlong-zhua");
	map_skill("sword", "yunlong-jian");
	map_skill("whip", "yunlong-bian");

	prepare_skill("hand","yunlong-shou");
	prepare_skill("claw","yunlong-zhua");

	set("chat_chance_combat", 70);  
	set("chat_msg_combat", ({
                (: perform_action, "sword.xian" :),
                (: perform_action, "sword.duoming" :),
                (: perform_action, "sword.guang" :),
                (: perform_action, "sword.jueming" :),
                (: perform_action, "sword.shen" :),                	
                (: perform_action, "sword.xunlei" :),                	                	
                (: exert_function, "recover" :),
                (: perform_action, "unarmed.pofuchenzhou" :),

	}) );

	set("chat_chance", 5);
	set("chat_msg", ({
	"�����ǿ�����˵:�����Ҳ��ԩ��?\n",
	"������Ŀ��ǰ��˵:������Ϊ�����Ϸ�����㶪���Դ�\n",
}));
	set("inquiry", ([
	"����": "������������˵:�뵱����Ҫ����������ֲ��ܰ�!\n",
	"��״": "�����˭,�Ⱥ��ҿ��Ǻ������ĺù�Ŷ!\n",
	"����": "�����پ�������������(dangguan)\n",
]));
        setup();
          carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/shan-jian")->wield();
}

int accept_object(object who, object ob)
{

if (!ob->query("money_id") )
	{
	tell_object(who, "�ղ���˲�Ȼ��ŭ��˵����ʲô?���ҶԱ����лߣ�\n");
	message_vision(HIY"�����Ǵ�ȵ�:�󵨿�ͽ,�����лߣ����˸�������ȥ��!!\n"+
			"������ǿ��׳������һӶ����,��$N����һ��,���Ű���\n"+
			"���������$N����,���$N�޵�����\n"NOR,who);
	message_vision(HIR"ͻȻ$N������,һ������������������߶����˼���\n"+
			"ֻ��������˵:���յ�ҷŹ����´��ٷ���������,����!!\n"NOR,who);
ob->start_busy(100);
	who->unconcious();
        return 0;
	}     
         if (ob->query("money_id") && ob->value() < 10000000)
	{
	tell_object(who, "�ղ���˲�Ȼ��ŭ��˵����ʲô?���ҶԱ����лߣ�\n");
	message_vision(HIY"�����Ǵ�ȵ�:�󵨿�ͽ,�����лߣ����˸�������ȥ��!!\n"+
			"������ǿ��׳������һӶ����,��$N����һ��,���Ű���\n"+
			"���������$N����,���$N�޵�����\n"NOR,who);
	message_vision(HIR"ͻȻ$N������,һ������������������߶����˼���\n"+
			"ֻ��������˵:���յ�ҷŹ����´��ٷ���������,����!!\n"NOR,who);
ob->start_busy(100);
	who->unconcious();
        return 0;
	}
        else 
        {
	message_vision(HIY"�����Ƕ�$N�ٺٵ�Ц�˼�����\n"NOR,who);
        who->set_temp("gao_paid",1);
	}
	return 1;      
}

void beating(object ob)
{
if (!ob) return;
	message_vision(HIY"�����Ǵ�ȵ�:�󵨿�ͽ,�����ܸ�,����,��������ȥ��!!\n"+
			"������ǿ��׳������һӶ����,��$N����һ��,���Ű���\n"+
			"���������$N����,���$N�޵�����\n"NOR,ob);
	message_vision(HIR"ͻȻ$N������,һ������������������߶����˼���\n"+
			"ֻ��������˵:���յ�ҷŹ����´��ٷ���������,����!!\n"NOR,ob);
ob->move("/d/kaifeng/jianyu");
ob->start_busy(100);
	ob->unconcious();
}

void beating2(object ob)
{
if (!ob) return;
	message_vision(HIY"�����Ǵ�ȵ�:�󵨿�ͽ, �����㷸�˰��ɣ�����,��������ȥ��!!\n"+
			"������ǿ��׳������һӶ����,��$N����һ��,���Ű���\n"+
			"���������$N����,���$N�޵�����\n"NOR,ob);
	message_vision(HIR"ͻȻ$N������,һ������������������߶����˼���\n"+
			"ֻ��������˵:���յ�ҷŹ����´��ٷ���������,����!!\n"NOR,ob);
	ob->move("/d/kaifeng/jianyu");
ob->start_busy(100);
	ob->unconcious();
}


void dzj(object ob)
{
int j;
if (!ob) return;
message_vision(HIY"�������۸ߺ�:��~~��~~~!!\n"NOR,ob);
j=random(3);
if (j == 0)
{
remove_call_out("beating");
call_out("beating", 3, ob);
return ;
}
call_out("dzj",j--, ob);
}

void dzj2(object ob)
{
int j;
if (!ob) return;
message_vision(HIY"�������۸ߺ�:��~~��~~~!!\n"NOR,ob);
j=random(3);
if (j == 0)
{
remove_call_out("beating2");
call_out("beating2", 3, ob);
return ;
}
call_out("dzj2",j--, ob);
}

void del_gaoed(object me)
{
if (!me) return;
        if (objectp(me) &&  me->query_temp("gaoed"))
                me->delete_temp("gaoed");
}

int do_gao(string str)
{
	object ob,me;
	int i;
       me=this_player();
       if (!me->query_temp("gao_paid")) return notify_fail("����ôҲ�ý����������\n");
       if (me->query_temp("gaoed"))
                return notify_fail("��ողŸ���ˣ���ô������! \n");
       if (!str) return notify_fail("<Syntax>: gao <player id>\n");
                   ob=find_player(str);
      if (!ob) ob= find_living(str);	
      if (!ob) return notify_fail("�Ҳ�����Ҫ���ɷ���\n");
      if (me->query("killbyname")!=ob->query("name")) return notify_fail("�������û��������ʲô����\n");
      
      me->set_temp("gaoed",1);
      if (me->query("pks")>random(50)||me->query("combat_exp")<random(500000))  
        {call_out("dzj", 5, me); }
      else {
        call_out("del_gaoed", 3000, me);
        me->delete_temp("gao_paid");
     	tell_room(environment(ob),"һȺ����һӵ���ϣ���"+
	(string)ob->query("name")+"ץ������, Ȼ�������.\n", ob);
	tell_object(ob,"һȺ����һӵ���ϣ�����˵�����˸����ˣ���������һ��\n");
	ob->start_busy(50);
	me->set("killbyname",0);
	me->delete("killbyname");
	ob->set_temp("summon_time",time());
	ob->move(environment(me));
        tell_object(me, (string)ob->query("name")+"��ץ��������.\n");
	tell_object(ob,"�㷢����"+(string)me->query("name")+
	"�����.\n");
	tell_room(environment(ob),(string)ob->query("name")+"ͻȻ��ץ"+
	"����������\n",({me,ob}));
	message_vision("\n$N����$nվ�ڴ����ϰ�Ц��ֹ,�����Ļ�����"
		+(string)me->query("name")+ "���ǵ�����!\n",ob,me);
         call_out("dzj2", 5, ob);	
       }
       return 1;
}


int xiao_li()
{
 object ob;
 ob=this_player();
if (ob->is_busy())
{
	command("say ����æ���ء�\n");
return 1;
}
	if(ob->query("combat_exp")<5000&&ob->query("meili")<500){
	command("say ��������,��Ҫ��������֮��,����ʲô������\n")
;
}
else  {
	command("smile");
	command("say �ܺ�,��ͥ��������֮����" + ob->query("name") + 
        "������Ϊ��ͥЧ����������֮���ã�\n");
	ob->set("class", "officer");
	ob->set("weiwang", 0);
}
if (ob->query("class")=="officer"){ 
       if ((ob->query("combat_exp")<10000)&&(ob->query("combat_exp")>5000)) ob->set("title", "����Ժ����");
 else if (ob->query("combat_exp")<15000) ob->set("title","������ʦү");
else if (ob->query("combat_exp")<40000) ob->set("title","��������");
else if (ob->query("combat_exp")<65000) ob->set("title","ѩͤ������");
 else if (ob->query("combat_exp")<80000) ob->set("title", "ƽ������");
else if (ob->query("combat_exp")<135000) ob->set("title", "��ͬ����");
else if (ob->query("combat_exp")<240000) ob->set("title", "��������");
else if (ob->query("combat_exp")<345000) ob->set("title", "��������");
else if (ob->query("combat_exp")<450000) ob->set("title", "ͩ������");
else if (ob->query("combat_exp")<560000) ob->set("title", "������");
else if (ob->query("combat_exp")<670000) ob->set("title", "����֪��");
else if (ob->query("combat_exp")<700000) ob->set("title", "����֪��");
else if (ob->query("combat_exp")<820000) ob->set("title", "����֪��");
else if (ob->query("combat_exp")<950000) ob->set("title", "�Ͼ�֪��");
else if (ob->query("combat_exp")<1200000) ob->set("title", "�����ᶽ");
else if (ob->query("combat_exp")<1250000) ob->set("title", "�ƹ��ܶ�");
else if (ob->query("combat_exp")<1300000) ob->set("title", "�����ܶ�");
else if (ob->query("combat_exp")<2350000) ob->set("title", "�����ܶ�");
else if (ob->query("combat_exp")<3400000) ob->set("title", "������Ա����");
else if (ob->query("combat_exp")<4500000) ob->set("title", "������");
else if (ob->query("combat_exp")<5600000) ob->set("title", "��������");
else if (ob->query("combat_exp")<6800000) ob->set("title", "�մ���ͼ���ѧʿ");
else if (ob->query("combat_exp")<7000000) ob->set("title", "��ة��");
else if (ob->query("combat_exp")<8200000) ob->set("title", "��ة��");
else if (ob->query("combat_exp")<10000000) ob->set("title", "�մ�һ��ǧ�ﲮ");
else if (ob->query("combat_exp")<12000000) ob->set("title", "�մͶ����򻧺�");
else if (ob->query("combat_exp")<13000000) ob->set("title", "�մ�һ�ȶ�����");
else if (ob->query("combat_exp")<15000000) ob->set("title", "�մͶ��Ȼ�����");
else if (ob->query("combat_exp")<28000000) ob->set("title", "�մ�һ��¹����");
else if (ob->query("combat_exp")<50000000) ob->set("title", "�մ��ص�ƽ����");
else ob->set("title", "����ͳ��");
tell_object(ob,"�����ڵĹ�����[["+ob->query("title")+"]]\n");}
message("system", HIY"ʥּ��
����"+ob->query("name")+"ִ���з�����Ϊ�ν�
�Ӽ���������Ϊ��"+ob->query("title")+"����
��"+ob->query("name")+"�ܼ���Ϊ��ͥЧ�ң�
			�մ�\n"NOR,users());
ob->start_busy(10);
       return 1;
 
}

