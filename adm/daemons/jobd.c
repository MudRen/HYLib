#include <ansi.h>

inherit F_DBASE;
#define MPFILE "/data/npc/menpai.o"
#define MPFILEA "/data/npc/menpai1.o"
void init_creat_job();
void get_job();
void do_clone(mapping target);
mapping *where=({
        (["party":        "������",
        "where" :         "/d/shaolin/guangchang2",]),
        (["party":      "�䵱��",
        "where" :       "/d/wudang/guangchang",]),
        (["party":       "���չ�",
        "where" :       "/d/lingjiu/dating",]),
        (["party":       "��ɽ��",
        "where" :       "/d/huashan/qunxianguan",]),
        (["party":       "ؤ��",
         "where" :       "/d/city/pomiao",]),
         (["party":       "����μ�",
         "where" :       "/d/dali/wfdating",]),
       (["party":       "��Ĺ��",
         "where" :       "/d/gumu/qianting",]),
              (["party":       "������",
         "where" :       "/d/xingxiu/xxh2",]),
               (["party":       "������",
         "where" :       "/d/shenlong/dating",]),
               (["party":       "��ң��",
         "where" :       "/d/xiaoyao/qingcaop",]),
               (["party":       "���ư�",
         "where" :       "/d/tiezhang/wztang",]),
                (["party":       "������",
         "where" :       "/d/kunlun/guangchang",]),
               (["party":       "�һ���",
         "where" :       "/d/taohua/dating",]),
              (["party":       "����ɽ��",
         "where" :       "/d/baituo/dating",]),
               (["party":       "ѩɽ��",
         "where" :       "/d/xueshan/dadian",]),
               (["party":       "ȫ���",
         "where" :       "/d/quanzhen/datang1",]),
                (["party":       "����Ľ��",
         "where" :       "/d/mr/yanziwu",]),
                (["party":       "������",
         "where" :       "/d/lingxiao/dadian",]),
                (["party":       "�嶾��",
         "where" :       "/d/wudujiao/dating",]),
                (["party":       "����",
         "where" :       "/d/tangmen/liujiantang",]),
                (["party":       "����������",
         "where" :       "/d/feitian/daochang",]),

 });
 
mapping *where2=({
        (["party":        "������",
        "where" :         "/d/shaolin/guangchang2",]),
        (["party":      "�䵱��",
        "where" :       "/d/wudang/guangchang",]),
        (["party":       "���չ�",
        "where" :       "/d/lingjiu/dating",]),
        (["party":       "��ɽ��",
        "where" :       "/d/huashan/qunxianguan",]),
        (["party":       "ؤ��",
         "where" :       "/d/city/pomiao",]),
         (["party":       "����μ�",
         "where" :       "/d/dali/wfdating",]),
       (["party":       "��Ĺ��",
         "where" :       "/d/gumu/qianting",]),
              (["party":       "������",
         "where" :       "/d/xingxiu/xxh2",]),
               (["party":       "������",
         "where" :       "/d/shenlong/dating",]),
               (["party":       "��ң��",
         "where" :       "/d/xiaoyao/qingcaop",]),
               (["party":       "���ư�",
         "where" :       "/d/tiezhang/wztang",]),
                (["party":       "������",
         "where" :       "/d/kunlun/guangchang",]),
               (["party":       "�һ���",
         "where" :       "/d/guiyun/qianyuan",]),
              (["party":       "����ɽ��",
         "where" :       "/d/baituo/dating",]),
               (["party":       "ѩɽ��",
         "where" :       "/d/xueshan/dadian",]),
               (["party":       "ȫ���",
         "where" :       "/d/quanzhen/datang1",]),
                (["party":       "����Ľ��",
         "where" :       "/d/mr/yanziwu",]),
                (["party":       "������",
         "where" :       "/d/lingxiao/dadian",]),
                (["party":       "�嶾��",
         "where" :       "/d/wudujiao/dating",]),
                (["party":       "����",
         "where" :       "/d/tangmen/liujiantang",]),
                (["party":       "����������",
         "where" :       "/d/feitian/daochang",]),

 });	

void create()
{
        seteuid(getuid());
        set("channel_id", "������");
        set("id", "JOB");
        init_creat_job();
}
void init_creat_job()
{
        CHANNEL_D->do_channel( this_object(), "sys", "�ƽ�������سɹ���");
        remove_call_out("get_job");
  call_out("get_job",600);
}
void get_job()
{
        object *obs = users(), ob, robot,killer1,killer2;
        string ppl;
        mapping target;
        string *dir,roomname;
        object room;
        int i,j,k,a,b,c;
        target=where[random(sizeof(where))];
if (random(2)==0)
target=where2[random(sizeof(where2))];	
                j=random(24)+1;
        robot = clone_object("/quest/haojie/jobnpc/"+j);
if (robot->query("family/family_name") == target["party"])
{
j=random(24)+1;
robot = clone_object("/quest/haojie/jobnpc/"+j);
}
if (robot->query("family/family_name") == target["party"])
{
j=random(24)+1;
robot = clone_object("/quest/haojie/jobnpc/"+j);
}

if (robot->query("family/family_name") != target["party"])
{
message("channel:chat", HIC"\n�������ƽ١�"+robot->query("family/family_name") + ":�ڵ�������!"NOR"��\n", users());
message("channel:chat", HIC"\n�������ƽ١�"+robot->query("family/family_name") + ":˳����������������!"NOR"��\n", users());
message("channel:chat", HIC"\n�������ƽ١�"+robot->query("family/family_name") + ":" + target["party"]+"���������ԣ���һ���ı�Ҫ����"+target["party"]+"!"NOR"��\n", users());
write_file(MPFILE,sprintf("%s",
	robot->query("family/family_name")),1);

write_file(MPFILEA,sprintf("%s",
	target["party"]),1);
a=random(3000000)+1000000;
b=random(6000)+1800;
c=random(420)+100;        
        remove_call_out("do_dest");
        call_out("do_dest",800,robot);
        for(k=0;k<=7;k++)
        {
                killer1=clone_object("/quest/haojie/jobnpc/"+j);
                killer1->set("hated",target["party"]);
                if( room = find_object(target["where"]+".c")){
                        CHANNEL_D->do_channel( this_object(), "sys","���ҳɹ���Ŀǰ"+killer1->query("name")+"��"+file_name(room)+"\n");
                killer1=clone_object("/quest/haojie/jobnpc/"+j);
                killer1->set("hated",target["party"]);
                killer1->set("combat_exp",a);
                killer1->set("max_qi",b);
                killer1->set("qi",b);
                killer1->set("max_jing",b);
                killer1->set("jing",b);
                killer1->set("max_neili",b*2);
                killer1->set("neili",b*2);
                killer1->move(room);
                killer1->random_move();
                }else if(room = load_object(target["where"]+".c")){
                        CHANNEL_D->do_channel( this_object(), "sys","���ҳɹ���Ŀǰ"+killer1->query("name")+"��"+file_name(room)+"\n");
                killer1=clone_object("/quest/haojie/jobnpc/"+j);
                killer1->set("hated",target["party"]);
                killer1->set("combat_exp",a);
                killer1->set("max_qi",b);
                killer1->set("qi",b);
                killer1->set("max_jing",b);
                killer1->set("jing",b);
                killer1->set("max_neili",b*2);
                killer1->set("neili",b*2);
                killer1->move(room);
                killer1->random_move();
                }
        }
}
}

void do_dest(object robot)
{
        object *obj=users(),ob;
       int i;
message("channel:chat", HIC"\n�������ƽ١�"+robot->query("family/family_name") + ":�ߣ���ξ��ȷ�����һ���´�һ��ɱ�����Ǽ�Ȯ������"NOR"��\n", users());
//        CHANNEL_D->do_channel(robot, "chat",HIR"�ߣ���ξ��ȷ�����һ���´�һ��ɱ�����Ǽ�Ȯ������"NOR);
        destruct(robot);
        remove_call_out("get_job");
        call_out("get_job",1800);
}
