#include <ansi.h>
inherit NPC;

int give_chuan();

void create()
{
  set_name(YEL"½��"NOR, ({"lu hai", "lu"}));
  set("gender", "����");
  set("age", 76);
  set ("title","<��������ס��>  "+YEL"����һ��"NOR);
  set("attitude", "friendly");
  set("combat_exp", 350000);
  set("per", 25);
  set_skill("dodge", 60);
  set("max_sen",600);
  set("max_gee",600);
  set("max_gin",600);
  set("force",800);
  set("max_force",800);
  set("force_factor",25);
  set_skill("unarmed",360);
  set_skill("parry",360);
  set_skill("dodge",360);
	set_temp("apply/attack",220);
	set_temp("apply/defense",220);
	set_temp("apply/armor",220);
	set("max_neili",1500+random(5550));
	set("max_jing",1500+random(5550));
		set("max_qi",1500+random(5550));	

  setup();

  set("inquiry", ([
       "here": "��֪������ʲô�ط�,����ð�����һ��������ʮ��,�������̵ġ�\n",
       "������ѩ��": (: give_chuan :),
       "��ȥ": "Ҫ���Ǹ��������ס��,���ӻ����������ô?\n",
       "����": "�������ú��׺�������,ֻ������ŵĺ���ն����ն�ϡ�\n",
       "�����":"���������Ǹ��������,����˭?\n",
       "������":"�������ú��׺�������,ֻ������ŵĺ���ն����ն��.\n",
      ]));
}

int give_chuan()
{
  object me = this_object();
  object who = this_player();
message_vision("$N��$n�ٺ�һ����Ц,˭�ܸ��Ұ�����ʲ������������,�������!\n",me,who);
return 1;
} 
