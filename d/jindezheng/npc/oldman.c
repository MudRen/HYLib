inherit NPC;
void create()
{
     set_name("˵������",({"oldman","shuoshu"}));
     set("gender","����");
     set("shen_type",1);
     set("age",70);
     set("combat_exp",300000);
     set("str",34);
     set("per",30);
     set_skill("unarmed",90);
     set_skill("dodge",90);
     set_skill("parry",90);
     set("chat_chance",8);
     set("chat_msg",({
            "˵�����˵���ˮ����ɽ�ۼ���һ��Ӣ�ۺú���Ҫ������Ҹ�һ������!\n",
            "˵�����˺��˿ڲ����˵����ɽ����λ�ú��ӣ��˳�[��ʱ��]�ĺ��������ɾ���!\n",
            "˵�����˵�����ʮ�������ͷ�ֳ壬���˸�ٴ���ݺ����������!\n",
       }));
     setup();
    carry_object("/clone/misc/cloth")->wear();
    add_money("silver",50);
}
