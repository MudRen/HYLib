// ���

inherit NPC;

int do_out();

void create()
{
        set_name("���", ({ "ma fu", "ma", "fu" }));
        set("gender", "����");
        set("age", 25);
        set("long", "�����Ǻ���ׯר�Ŵ������뿪��������\n");
        
        set("combat_exp", 7000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        setup();
        set("inquiry", ([
                "�뿪"     : (: do_out :),
        ])); 
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 2);
}
int do_out()
{
  object me, ob ;
  
  me= this_player();

  ob= this_object();

  say("���һ������"+(string)me->query("name")+"˵�����������ϳ�����\n");

  say((string)me->query("name")+"�������˺���ׯ��\n");

  me->move("/d/pingan/guangchang");

  return 1;
}  
