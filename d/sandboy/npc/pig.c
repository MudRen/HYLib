inherit NPC;

void create()
{
        set_name("�����", ({ "pig", "zhu" }) );
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 30);
        set("long", "һֻ�Ե÷�ͷ�������,�벻֪ɱ�ٽ��١�\n");
        set("attitude", "friendly");
   set("looking", "�ʷ����֣����������ж������");
        set("str", 20);
        set("dex", 40);
   set("qi", 300);
   set("jing", 300);
        set("limbs", ({ "ͷ��", "����" }) );
        set("verbs", ({ "bite"}) );
   set("combat_exp", 2000);
        set_skill("dodge", 20);
        set_temp("apply/armor", 30);

        setup();
}
void die()
{
           message("vision",
               name() + "�ߺ�ߴߴ�ؽ��˼���������³�һ��Ѫˮ,���ˡ�\n", environment(),
                this_object() );
  new("/d/sandboy/obj/meat.c")->move(environment(this_object()));
        destruct(this_object());
   return;
}
