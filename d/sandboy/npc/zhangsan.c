inherit NPC;
void create()
{
     set_name("��ɽ",({"zhang san","zhang"}));
     set("gender","����");
     set("title","����");
     set("long","����ɽ�еĴ���������Ϊ��!\n");
     set("age",34);
     set("shen_type",1);
     set("score",100);
     set("combat_exp",50000);
     set("inquiry",([
       "����":"�������洫�Ķ���������������!\n",
       "����":"�����������Ǳ����˸�Ȧ�ף����ĸ�ɵ�ϻ��ϵ�!",
       ]));
      set("chat_chance",10);
      set("chat_msg",({
           "��ɽ�������²��˲�ͷ�ϵĺ�ˮ!\n",
           "��ɽ���ɵĿ�����һ�ۣ��ֳ����濴��!\n",
           "��ɽ���˿����еĿ��񵶣����������п�������һ��!\n",
           "��ɽ�������еĵ������ǵؿ���������!\n",
          }));
       setup();
  carry_object("/d/sandboy/obj/bamboo_blade")->wield();
}