inherit NPC;

string *names = ({
"Сë¿",
"��ë¿",
});

void create()
{
  set_name(names[random(sizeof(names))], ({"mao lu", "lu"}));
  set("race", "Ұ��");
  set("age", 10);

  set("combat_exp", 10000);
  set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
  set("verbs", ({ "bite"}));

  set("chat_chance", 3);
  set("chat_msg",({
                 (:random_move:),
}));
  set_temp("apply/attack", 10);
  set_temp("apply/armor", 20);

  setup();
}

