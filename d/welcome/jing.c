#include <ansi.h>
inherit NPC;

string ask_liwu();

void create()
{
        set_name(HIG"��ӹ"NOR, ({ "jin yong","jing" }) );
  set("title", HIM "��������" NOR);
	set("gender", "����" );
	set_temp("no_kill", 1);
	set("age", 76);
	set("per", 100);
        set("long", "�����Ǵ�����ӹ�����������Ҫ����\n");
	set("shen_type",1);
	set("combat_exp", 2000000);
	set("attitude", "peaceful");
        set("apply/attack", 350);
	set("apply/defense", 350);

	set_skill("unarmed", 150);
	set_skill("blade", 150);
	set_skill("parry", 40);
	set_skill("dodge", 150);
set("chat_chance",10);
        	 set("chat_msg", ({
		"��ӹ����������� ��Ϊ���� ֱ����������\n",
		"��ӹ��������ϵر�˫�ɿ� �ϳἸ�غ���\n",
		"��ӹ���������Ȥ ���� ���и��гն�Ů\n",
		"��ӹ�������Ӧ���� ���������\n"
		"��ӹ����������� ��Ϊ���� ֱ����������\n",
		"��ӹ��������ϵر�˫�ɿ� �ϳἸ�غ���\n",
		"��ӹ���������Ȥ ���� ���и��гն�Ů\n",
		"��ӹ�������Ӧ���� ���������\n"
		"��ӹ������Կ��Ϻ�ӧ���⹳˪ѩ���������հ����������ǡ�\n",
		"��ӹ�����ʮ��ɱһ�ˣ�ǧ�ﲻ���У����˷���ȥ�������������\n",
		"��ӹ������й����������ѽ�ϥǰ�ᡣ������캥������Ȱ������\n",
		"��ӹ�����������Ȼŵ��������Ϊ�ᡣ�ۻ����Ⱥ�������������\n",		
		"��ӹ��������Իӽ𴸣��������𾪣�ǧ���׳ʿ���Ӻմ����ǡ�\n",
                "��ӹ��������������㣬��������Ӣ��˭������£�����̫������\n",
	}) );
	set("inquiry" , ([
             "gift" : (: ask_liwu :),
             "����" : (: ask_liwu :),
             "liwu" : (: ask_liwu :),
	]));
	setup();
}

string ask_liwu()
{
  object me=this_player();
  int exp_bound,qn_bound,neili;

  if(me->query("liwu_bound")>0)
  {
   return "�Ѿ����������������˶�!";
  }
  exp_bound=random(8000)+8000;
  qn_bound=random(8000)+2000;
  neili=random(200)+180;

  //command("chat "HIR+me->query("name")+HIC"�õ��ҵĽ��������书��20��!");
  command("say "HIR+me->query("name")+HIC" ��ӭ������������һ�� ����II����������!");
//command("say "HIR+me->query("name")+HIC" ��ӭ������������һ�� ����II����������!");
//command("say "HIR+me->query("id")+HIC" ����������֣�����help -old��һ�°���!");
//command("say "HIR+me->query("id")+HIC" help aboutquest������˵��!");
//command("say "HIR+me->query("id")+HIC" help wlmm�ǳ���˵��!");
//command("say "HIR+me->query("id")+HIC" help maps�ǳ��������ͼ!");
//command("say "HIR+me->query("id")+HIC" help menpai������˵��!");
//command("say "HIR+me->query("id")+HIC" help shuoming4��·������!");
  //command("say "HIR+me->query("name")+HIC"ֻ�о������5000���ܱ�����20���书!");
  //command("chat "HIR+me->query("name")+HIC"�õ��ҵĽ���Ǳ��:"HIR+qn_bound+HIC"!");
  //command("es "HIG+me->query("name")+HIC"�����˺���II�Ϻ���վ"HIR+"IP 202.101.10.187 PORT 5555"+HIC"���õ��˽���!");
        tell_object(me,HIW"�㱻�����ˣ�\n" + 
        chinese_number(exp_bound) + "��ʵս����\n" +
        chinese_number(qn_bound) + "��Ǳ��\n"+
        chinese_number(neili) + "������\n"+
        NOR);
  me->add("combat_exp",exp_bound);
  me->add("potential",qn_bound);
me->add("max_neili", neili);



if (me->query_skill("unarmed")<30)
{
  me->set_skill("unarmed",30);
}
if (me->query_skill("parry")<30)
{
  me->set_skill("parry",30);
}
if (me->query_skill("dodge")<30)
{
  me->set_skill("dodge",30);
}
if (me->query_skill("force")<30)
{
  me->set_skill("force",30);
}

if (me->query_skill("literate")<30)
{
  me->set_skill("literate",30);
}
  me->set("liwu_bound",1);
  return "��ӭ���ٺ���II��";
}
