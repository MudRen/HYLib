// yuzu.c
// cgm 28/12/1999
// idea 7/4/2000

#include <ansi.h>

inherit NPC;

string *msg_d = ({
                      "�����","�����","ɵB","�Ҳ�","����","������˯",
                      "�٣�","��!","fuck","FUCK","Fuck","���",
                      "�����̵�","����������","�����","��үү��",
                      "�������ƨ","tmd","TMD","tmmd","TMMD","������","������","������",
                      "�����","��ƨwiz","��wiz","��wiz","������",
                      "������","�����","������","�ƣգã�","F u c k"
                      ,"f u c k","�����","�����","ɵB","�Ҳ�","����","������˯",
                      "ta nai nai de","tanainaide","tanai naide","ta nainai de","tanainai de",
                      "�٣�","��!","fuck","FUCK","Fuck","���",
                      "t nn d","tnnnnd","tnn d","t nnd","t n n d","tn nd","t.m.d"
                      "�����̵�","����������","�����","��үү��","t.n.n.d","tnnd"
                      "Сƨ��","shit",
                      "�������ƨ","tmd","TMD","tmmd","TMMD","������","������","������",
                      "�����","��ƨwiz","��wiz","��wiz","������","tnnd","TNND","�����̵�",
                      "����","��wiz","���","����","������","������","ǿ��","����",
                      "���","���","����",
                      });


void create()
{
        set_name("����", ({"yu zu","yuzu"}));
        set("title", HIY"�������Ÿ��֡�"NOR);
        set("gender", "����" );
        set("age", 30);
        set("per", 5);
        set("long", HIR"һ�����ص����䣬��������׼�������ʲô���¡�\n"NOR);
        set("combat_exp", 10000000);
        set("attitude", "peaceful");
        set("dex", 50);
        set("str", 50);
   
        set_skill("literate", 800);
        set("max_qi", 1000);
        set("max_jing", 500);
        set("max_neili", 1000);
  	
  	set("no_clean_up",1);
        setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/city/obj/gangjian")->wield();

	if( !clonep() ) CHANNEL_D->register_relay_channel("rumor");
	if( !clonep() ) CHANNEL_D->register_relay_channel("chat");
	if( !clonep() ) CHANNEL_D->register_relay_channel("party");
        if( !clonep() ) CHANNEL_D->register_relay_channel("es");
        if( !clonep() ) CHANNEL_D->register_relay_channel("sing");
        
}

void relay_channel(object criminal, string channel, string msg)
{

        int i;
        string criname,result;
        int howlong;
        if( !userp(criminal) ) return;

        for(i=0; i<sizeof(msg_d); i++)
        {
            if( strsrch(msg, msg_d[i]) >= 0)
                   {
                    message_vision(CYN"�����Ÿ��ֺ�Ȼ���֣��ӳ����ף�һ�¾���ס$N�Ĳ��ӡ�\n$N�쳤��ͷ�����Ű��۵ر������ˡ�\n"NOR, criminal);
                    
                    criname = criminal->query("name") + "("+criminal->query("id")+")";
                    howlong=10;
                    
                    result = sprintf("%s��%sƵ��˵�໰(%s)�������� %d ��\n",
                    criname,channel,msg,howlong);

                    criminal->set("qiushi/howlong",howlong);
                    criminal->set("qiushi/temp",result);
                    criminal->move("/d/death/qiushi");
                    
                    
                    message("channel:rumor",HIM"��ҥ�ԡ�ĳ�ˣ���˵"+criname+"�ڹ���Ƶ��ʹ�ô�������������Ÿ���ץ���ˡ�\n"NOR, users());
                    return;
                    }
        }
}