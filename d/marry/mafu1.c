// ���

inherit NPC;

int do_hunli();

void create()
{
        set_name("���", ({ "ma fu", "ma", "fu" }));
        set("gender", "����");
        set("age", 25);
        set("long", "�����Ǻ���ׯר�Ž���ȥ�μӻ�������\n");
        
        set("combat_exp", 7000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set("inquiry", ([
                "����"     : (: do_hunli :),
                "�μӻ���" : (: do_hunli :),
        ])); 
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 2);

}
int do_hunli()
{
  object me, ob ;
  
  me= this_player();

  ob= this_object();

 if (!( present("qing tie", me)) )
        {
             say("����˷�����˵�������������𣿡�\n");
             return 1;
        }

  say("���һ������"+(string)me->query("name")+"˵�����������ϳ�����\n");

  say((string)me->query("name")+"�������˺���ׯ��\n");

me->move("/d/marry/honglou");

  return 1;
}  
